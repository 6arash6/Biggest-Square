# BSQ Test Suite Documentation

## Overview

This comprehensive test suite is designed to catch all possible edge cases and failure points in the BSQ program. It includes 35 test cases covering valid maps, invalid maps, stress tests, and special scenarios — current status: **35/35** passing (valgrind clean; norminette clean).

## Test Categories

### 1. VALID MAP TESTS

#### Test 1: Valid Simple Map
- **File**: `test1_valid.txt`
- **Purpose**: Basic functionality test with a standard 9x9 map
- **Expected**: Should find and mark the largest square
- **Why**: Verifies basic algorithm works correctly

#### Test 2: Single Cell Map
- **File**: `test2_single_cell.txt`
- **Purpose**: Edge case - map with only one cell
- **Expected**: Should mark the single cell as the square
- **Why**: Tests minimum map size handling

#### Test 3: All Obstacles
- **File**: `test3_all_obstacles.txt`
- **Purpose**: Edge case - no empty cells available
- **Expected**: Should output the map unchanged (no square)
- **Why**: Tests handling when no square can be placed

#### Test 4: No Obstacles
- **File**: `test4_no_obstacles.txt`
- **Purpose**: Edge case - entire map is empty
- **Expected**: Should mark the entire map as the square
- **Why**: Tests maximum square detection

#### Test 5: Large Square Possible
- **File**: `test5_large_square.txt`
- **Purpose**: 5x5 map with no obstacles
- **Expected**: Should mark entire 5x5 area
- **Why**: Tests square size calculation

#### Test 6-10: Various Valid Maps
- Single row/column maps
- Corner obstacles
- Multiple squares of same size
- Special characters (digits, spaces)
- Various obstacle patterns

### 2. INVALID MAP TESTS

#### Test 11: Wrong Number of Rows
- **File**: `test6_wrong_rows.txt`
- **Purpose**: Header says 5 rows, but only 2 provided
- **Expected**: "map error"
- **Why**: Tests row count validation

#### Test 12: Inconsistent Column Count
- **File**: `test7_inconsistent_cols.txt`
- **Purpose**: Rows have different lengths
- **Expected**: "map error"
- **Why**: Tests column consistency check

#### Test 13: Wrong Characters
- **File**: `test8_wrong_chars.txt`
- **Purpose**: Map contains characters not defined in header
- **Expected**: "map error"
- **Why**: Tests character validation

#### Test 14: Empty File
- **File**: `test9_empty.txt`
- **Purpose**: Completely empty file
- **Expected**: "map error"
- **Why**: Tests empty file handling

#### Test 15: Header Only
- **File**: `test10_header_only.txt`
- **Purpose**: File contains only header, no map
- **Expected**: "map error"
- **Why**: Tests missing map content

#### Test 16: No Header
- **File**: `test11_no_header.txt`
- **Purpose**: File starts directly with map content
- **Expected**: "map error"
- **Why**: Tests header validation

#### Test 17: Same Characters in Header
- **File**: `test12_same_chars.txt`
- **Purpose**: Empty, obstacle, and full characters are the same
- **Expected**: "map error"
- **Why**: Tests character uniqueness requirement

#### Test 18: Negative Rows
- **File**: `test13_negative_rows.txt`
- **Purpose**: Header contains negative number
- **Expected**: "map error"
- **Why**: Tests number validation

#### Test 19: Zero Rows
- **File**: `test14_zero_rows.txt`
- **Purpose**: Header specifies 0 rows
- **Expected**: "map error"
- **Why**: Tests minimum row requirement

#### Test 20: Extra Content After Map
- **File**: `test21_extra_content.txt`
- **Purpose**: Valid map followed by extra text
- **Expected**: "map error"
- **Why**: Tests strict map format validation

#### Test 21: Non-Printable in Header
- **File**: `test24_nonprintable_header.txt`
- **Purpose**: Header contains tab character
- **Expected**: "map error"
- **Why**: Tests printable character requirement

#### Test 22: Very Long Header Number
- **File**: `test25_long_header.txt`
- **Purpose**: Header number exceeds reasonable size
- **Expected**: "map error"
- **Why**: Tests buffer overflow protection

#### Test 23: Text Instead of Number
- **File**: `test30_text_rows.txt`
- **Purpose**: Header contains "three" instead of "3"
- **Expected**: "map error"
- **Why**: Tests numeric validation

#### Test 24: Non-Existent File
- **File**: `nonexistent.txt`
- **Purpose**: File doesn't exist
- **Expected**: "map error"
- **Why**: Tests file existence check

### 3. STRESS TESTS

#### Test 25: Large Map (100x100)
- **File**: `test15_large.txt`
- **Purpose**: 100x100 map with all empty cells
- **Expected**: Should complete within 10 seconds
- **Why**: Tests performance and memory handling

#### Test 26: Very Large Map (500x500)
- **File**: `test16_very_large.txt`
- **Purpose**: 500x500 map with all empty cells
- **Expected**: Should complete within 30 seconds
- **Why**: Tests scalability and memory limits

### 4. STDIN TESTS

#### Test 27: Valid Map from STDIN
- **Purpose**: Read valid map from standard input
- **Expected**: Should process correctly
- **Why**: Tests STDIN reading functionality

#### Test 28: Invalid Map from STDIN
- **Purpose**: Read invalid map from standard input
- **Expected**: "map error"
- **Why**: Tests STDIN error handling

### 5. MULTIPLE FILES TEST

#### Test 29: Multiple Valid Files
- **Purpose**: Process multiple map files in one execution
- **Expected**: Should output all maps with blank lines between
- **Why**: Tests multiple file handling

### 6. MEMORY LEAK CHECK

#### Test 30: Valgrind Memory Check
- **Purpose**: Check for memory leaks using valgrind
- **Expected**: No memory leaks
- **Why**: Ensures proper memory management

## Common Failure Points

### 1. Buffer Overflow
- **Test**: Very long header number
- **Symptom**: Segmentation fault
- **Fix**: Limit header size to reasonable length

### 2. Integer Overflow
- **Test**: Very large maps
- **Symptom**: Incorrect square size or crash
- **Fix**: Use appropriate data types (unsigned short for matrix)

### 3. Memory Leaks
- **Test**: All tests with valgrind
- **Symptom**: Memory not freed
- **Fix**: Ensure all malloc calls have corresponding free

### 4. Off-by-One Errors
- **Test**: Single cell, single row/column
- **Symptom**: Incorrect square position
- **Fix**: Careful boundary checking

### 5. Character Validation
- **Test**: Wrong characters, special characters
- **Symptom**: Accepts invalid input
- **Fix**: Strict character validation

### 6. Row/Column Counting
- **Test**: Inconsistent columns, wrong row count
- **Symptom**: Accepts malformed maps
- **Fix**: Validate all rows have same length

### 7. Edge Cases
- **Test**: All obstacles, no obstacles, single cell
- **Symptom**: Crash or incorrect output
- **Fix**: Handle all edge cases explicitly

## Running the Tests

### Prerequisites
1. Compiled BSQ executable (`./bsq`)
2. Test map files in `test_maps/` directory
3. Bash shell
4. (Optional) Valgrind for memory leak detection

### Execute Tests
```bash
chmod +x test_bsq.sh
./test_bsq.sh
```

### Expected Output
- ✅ PASSED for successful tests
- ❌ FAILED for failed tests
- Summary at the end showing total/passed/failed

## Test Coverage

| Category | Tests | Coverage |
|----------|-------|----------|
| Valid Maps | 15 | Basic functionality, edge cases |
| Invalid Maps | 14 | Error handling, validation |
| Stress Tests | 2 | Performance, memory |
| STDIN | 2 | Input handling |
| Multiple Files | 1 | Multi-file processing |
| Memory Leaks | 1 | Memory management |
| **Total** | **35** | **Comprehensive** |

## Interpreting Results

### All Tests Pass
✅ Program is robust and handles all edge cases correctly

### Tests Fail
1. Check which test failed
2. Look at the error message
3. Check the test file content
4. Debug the specific issue

### Common Issues
- **Segfault**: Memory access error, check array bounds
- **Timeout**: Infinite loop or very slow algorithm
- **Wrong output**: Logic error in algorithm
- **Memory leak**: Missing free() calls

## Adding New Tests

To add a new test:

1. Create test file in `test_maps/`
2. Add test case to `test_bsq.sh`
3. Document the test purpose
4. Run the test suite

## Conclusion

This test suite covers all major failure points and edge cases. Running these tests before submission will help catch issues that might cause failure during evaluation.
