#!/bin/bash

# BSQ Comprehensive Test Suite
# Tests all edge cases and potential failure points

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Counters
PASSED=0
FAILED=0
TOTAL=0

# Test function
run_test() {
    local test_name="$1"
    local test_file="$2"
    local should_succeed="$3"
    local timeout="$4"
    local check_nonexistent="$5"

    TOTAL=$((TOTAL + 1))

    echo "========================================"
    echo "Test $TOTAL: $test_name"
    echo "========================================"

    # For non-existent file test, skip file existence check
    if [ "$check_nonexistent" != "true" ]; then
        if [ ! -f "$test_file" ]; then
            echo -e "${RED}❌ FAILED: Test file not found${NC}"
            FAILED=$((FAILED + 1))
            return
        fi
    fi

    # Run with timeout
    if [ -z "$timeout" ]; then
        timeout=5
    fi

    # Capture output and return code
    OUTPUT=$(timeout "$timeout" ./bsq "$test_file" 2>&1)
    RETVAL=$?

    # Check for timeout
    if [ $RETVAL -eq 124 ]; then
        echo -e "${RED}❌ FAILED: Timeout after ${timeout}s${NC}"
        FAILED=$((FAILED + 1))
        return
    fi

    # Check for crash (segfault = 139, abort = 134)
    if [ $RETVAL -eq 139 ] || [ $RETVAL -eq 134 ]; then
        echo -e "${RED}❌ FAILED: Program crashed (signal $RETVAL)${NC}"
        FAILED=$((FAILED + 1))
        return
    fi

    if [ "$should_succeed" = "true" ]; then
        # Should succeed
        if [ $RETVAL -eq 0 ]; then
            echo -e "${GREEN}✅ PASSED${NC}"
            PASSED=$((PASSED + 1))
            echo "$OUTPUT" | head -5
        else
            echo -e "${RED}❌ FAILED: Expected success but got error${NC}"
            echo "$OUTPUT"
            FAILED=$((FAILED + 1))
        fi
    else
        # Should fail with "map error"
        if echo "$OUTPUT" | grep -q "map error"; then
            echo -e "${GREEN}✅ PASSED: Correctly detected error${NC}"
            PASSED=$((PASSED + 1))
        else
            echo -e "${RED}❌ FAILED: Should have printed 'map error'${NC}"
            echo "$OUTPUT"
            FAILED=$((FAILED + 1))
        fi
    fi

    echo ""
}

# Test STDIN
test_stdin() {
    local test_name="$1"
    local input_data="$2"
    local should_succeed="$3"

    TOTAL=$((TOTAL + 1))

    echo "========================================"
    echo "Test $TOTAL: $test_name (STDIN)"
    echo "========================================"

    OUTPUT=$(echo -e "$input_data" | timeout 5 ./bsq 2>&1)
    RETVAL=$?

    if [ "$should_succeed" = "true" ]; then
        if [ $RETVAL -eq 0 ]; then
            echo -e "${GREEN}✅ PASSED${NC}"
            PASSED=$((PASSED + 1))
            echo "$OUTPUT" | head -5
        else
            echo -e "${RED}❌ FAILED${NC}"
            echo "$OUTPUT"
            FAILED=$((FAILED + 1))
        fi
    else
        if echo "$OUTPUT" | grep -q "map error"; then
            echo -e "${GREEN}✅ PASSED: Correctly detected error${NC}"
            PASSED=$((PASSED + 1))
        else
            echo -e "${RED}❌ FAILED${NC}"
            echo "$OUTPUT"
            FAILED=$((FAILED + 1))
        fi
    fi

    echo ""
}

# Test multiple files
test_multiple_files() {
    local test_name="$1"
    shift
    local files=("$@")

    TOTAL=$((TOTAL + 1))

    echo "========================================"
    echo "Test $TOTAL: $test_name"
    echo "========================================"

    OUTPUT=$(timeout 10 ./bsq "${files[@]}" 2>&1)
    RETVAL=$?

    if [ $RETVAL -eq 0 ]; then
        echo -e "${GREEN}✅ PASSED${NC}"
        PASSED=$((PASSED + 1))
        echo "Processed ${#files[@]} files"
        echo "$OUTPUT" | head -10
    else
        echo -e "${RED}❌ FAILED${NC}"
        echo "$OUTPUT"
        FAILED=$((FAILED + 1))
    fi

    echo ""
}

# Check memory leaks (if valgrind available)
check_memory_leaks() {
    local test_file="$1"

    if ! command -v valgrind &> /dev/null; then
        echo -e "${YELLOW}⚠️  Valgrind not available - skipping memory check${NC}"
        return
    fi

    TOTAL=$((TOTAL + 1))

    echo "========================================"
    echo "Test $TOTAL: Memory Leak Check"
    echo "========================================"

    OUTPUT=$(valgrind --leak-check=full --error-exitcode=1 ./bsq "$test_file" 2>&1)
    RETVAL=$?

    if [ $RETVAL -eq 0 ]; then
        echo -e "${GREEN}✅ PASSED: No memory leaks${NC}"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}❌ FAILED: Memory leak detected${NC}"
        echo "$OUTPUT" | grep -A 10 "LEAK SUMMARY"
        FAILED=$((FAILED + 1))
    fi

    echo ""
}

# Main test execution
main() {
    echo "========================================"
    echo "BSQ COMPREHENSIVE TEST SUITE"
    echo "========================================"
    echo ""

    # Check if executable exists
    if [ ! -f "./bsq" ]; then
        echo -e "${RED}❌ Error: ./bsq executable not found${NC}"
        echo "Please compile first: make all"
        exit 1
    fi

    echo "Starting tests..."
    echo ""

    # VALID MAPS
    echo "========== VALID MAP TESTS =========="
    echo ""

    run_test "Valid simple map" "test_maps/test1_valid.txt" "true"
    run_test "Single cell map" "test_maps/test2_single_cell.txt" "true"
    run_test "All obstacles" "test_maps/test3_all_obstacles.txt" "true"
    run_test "No obstacles" "test_maps/test4_no_obstacles.txt" "true"
    run_test "Large square possible" "test_maps/test5_large_square.txt" "true"
    run_test "Single row" "test_maps/test17_single_row.txt" "true"
    run_test "Single column" "test_maps/test18_single_col.txt" "true"
    run_test "Corner obstacle" "test_maps/test19_corner_obstacle.txt" "true"
    run_test "Multiple squares same size" "test_maps/test20_multiple_squares.txt" "true"
    run_test "Digit characters" "test_maps/test22_digit_chars.txt" "true"
    run_test "Space characters" "test_maps/test23_space_chars.txt" "true"
    run_test "One empty cell" "test_maps/test26_one_empty.txt" "true"
    run_test "Checkerboard pattern" "test_maps/test27_checkerboard.txt" "true"
    run_test "Diagonal obstacles" "test_maps/test28_diagonal.txt" "true"
    run_test "Border obstacles" "test_maps/test29_border.txt" "true"
    run_test "Extra content after map" "test_maps/test21_extra_content.txt" "true"

    # STRESS TESTS
    echo "========== STRESS TESTS =========="
    echo ""

    run_test "Large map (100x100)" "test_maps/test15_large.txt" "true" "10"
    run_test "Very large map (500x500)" "test_maps/test16_very_large.txt" "true" "30"

    # INVALID MAPS
    echo "========== INVALID MAP TESTS =========="
    echo ""

    run_test "Wrong number of rows" "test_maps/test6_wrong_rows.txt" "false"
    run_test "Inconsistent column count" "test_maps/test7_inconsistent_cols.txt" "false"
    run_test "Wrong characters" "test_maps/test8_wrong_chars.txt" "false"
    run_test "Empty file" "test_maps/test9_empty.txt" "false"
    run_test "Header only" "test_maps/test10_header_only.txt" "false"
    run_test "No header" "test_maps/test11_no_header.txt" "false"
    run_test "Same characters in header" "test_maps/test12_same_chars.txt" "false"
    run_test "Negative rows" "test_maps/test13_negative_rows.txt" "false"
    run_test "Zero rows" "test_maps/test14_zero_rows.txt" "false"
    run_test "Non-printable in header" "test_maps/test24_nonprintable_header.txt" "false"
    run_test "Very long header number" "test_maps/test25_long_header.txt" "false"
    run_test "Text instead of number" "test_maps/test30_text_rows.txt" "false"
    run_test "Non-existent file" "test_maps/nonexistent.txt" "false" "5" "true"

    # STDIN TESTS
    echo "========== STDIN TESTS =========="
    echo ""

    test_stdin "Valid map from STDIN" "3.ox\n...\n...\n..." "true"
    test_stdin "Invalid map from STDIN" "invalid" "false"

    # MULTIPLE FILES TEST
    echo "========== MULTIPLE FILES TEST =========="
    echo ""

    test_multiple_files "Multiple valid files" \
        "test_maps/test1_valid.txt" \
        "test_maps/test4_no_obstacles.txt" \
        "test_maps/test5_large_square.txt"

    # MEMORY LEAK CHECK
    echo "========== MEMORY LEAK CHECK =========="
    echo ""

    check_memory_leaks "test_maps/test1_valid.txt"

    # SUMMARY
    echo "========================================"
    echo "TEST SUMMARY"
    echo "========================================"
    echo ""
    echo "Total tests: $TOTAL"
    echo -e "${GREEN}Passed: $PASSED${NC}"
    echo -e "${RED}Failed: $FAILED${NC}"
    echo ""

    if [ $FAILED -eq 0 ]; then
        echo -e "${GREEN}🎉 ALL TESTS PASSED!${NC}"
        exit 0
    else
        echo -e "${RED}⚠️  $FAILED TEST(S) FAILED${NC}"
        exit 1
    fi
}

# Run main
main
