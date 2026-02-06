# **************************************************************************** #
#                                                                              #
#    Makefile for Exam Practice Exercises                                     #
#    Compiles and tests all new exercises                                     #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Colors for output
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
RESET = \033[0m

# Exercise directories
EXERCISES = 2-aff_even 3-repeat_alpha 4-fizzbuzz 5-aff_odd 6-alpha_mirror 7-search_and_replace

.PHONY: all clean test_all help

# Default target
all: help

# Help message
help:
	@echo "$(BLUE)========================================$(RESET)"
	@echo "$(BLUE)  Exam Practice - Makefile Help        $(RESET)"
	@echo "$(BLUE)========================================$(RESET)"
	@echo ""
	@echo "Available targets:"
	@echo "  $(GREEN)make test_all$(RESET)      - Run all test files"
	@echo "  $(GREEN)make test_<name>$(RESET)   - Run specific test (e.g., make test_aff_even)"
	@echo "  $(GREEN)make compile_all$(RESET)   - Compile all tests without running"
	@echo "  $(GREEN)make clean$(RESET)         - Remove all compiled binaries"
	@echo "  $(GREEN)make help$(RESET)          - Show this help message"
	@echo ""
	@echo "Individual test targets:"
	@echo "  $(GREEN)make test_aff_even$(RESET)"
	@echo "  $(GREEN)make test_repeat_alpha$(RESET)"
	@echo "  $(GREEN)make test_fizzbuzz$(RESET)"
	@echo "  $(GREEN)make test_aff_odd$(RESET)"
	@echo "  $(GREEN)make test_alpha_mirror$(RESET)"
	@echo "  $(GREEN)make test_search_and_replace$(RESET)"
	@echo ""

# Test all exercises
test_all:
	@echo "$(BLUE)========================================$(RESET)"
	@echo "$(BLUE)  Running All Tests                    $(RESET)"
	@echo "$(BLUE)========================================$(RESET)"
	@echo ""
	@for ex in $(EXERCISES); do \
		echo "$(BLUE)Testing: $$ex$(RESET)"; \
		$(CC) $(CFLAGS) $$ex/test_*.c -o $$ex/test 2>&1; \
		if [ $$? -eq 0 ]; then \
			./$$ex/test; \
			rm $$ex/test; \
			echo ""; \
		else \
			echo "$(RED)Compilation failed for $$ex!$(RESET)"; \
			echo ""; \
		fi; \
	done
	@echo "$(GREEN)All tests completed!$(RESET)"

# Compile all without running
compile_all:
	@echo "$(BLUE)Compiling all test files...$(RESET)"
	@for ex in $(EXERCISES); do \
		echo "Compiling $$ex..."; \
		$(CC) $(CFLAGS) $$ex/test_*.c -o $$ex/test; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)✓ $$ex compiled successfully$(RESET)"; \
		else \
			echo "$(RED)✗ $$ex compilation failed$(RESET)"; \
		fi; \
	done

# Individual test targets
test_aff_even:
	@echo "$(BLUE)Testing: aff_even$(RESET)"
	@$(CC) $(CFLAGS) 2-aff_even/test_aff_even.c -o 2-aff_even/test
	@./2-aff_even/test
	@rm 2-aff_even/test

test_repeat_alpha:
	@echo "$(BLUE)Testing: repeat_alpha$(RESET)"
	@$(CC) $(CFLAGS) 3-repeat_alpha/test_repeat_alpha.c -o 3-repeat_alpha/test
	@./3-repeat_alpha/test
	@rm 3-repeat_alpha/test

test_fizzbuzz:
	@echo "$(BLUE)Testing: fizzbuzz$(RESET)"
	@$(CC) $(CFLAGS) 4-fizzbuzz/test_fizzbuzz.c -o 4-fizzbuzz/test
	@./4-fizzbuzz/test
	@rm 4-fizzbuzz/test

test_aff_odd:
	@echo "$(BLUE)Testing: aff_odd$(RESET)"
	@$(CC) $(CFLAGS) 5-aff_odd/test_aff_odd.c -o 5-aff_odd/test
	@./5-aff_odd/test
	@rm 5-aff_odd/test

test_alpha_mirror:
	@echo "$(BLUE)Testing: alpha_mirror$(RESET)"
	@$(CC) $(CFLAGS) 6-alpha_mirror/test_alpha_mirror.c -o 6-alpha_mirror/test
	@./6-alpha_mirror/test
	@rm 6-alpha_mirror/test

test_search_and_replace:
	@echo "$(BLUE)Testing: search_and_replace$(RESET)"
	@$(CC) $(CFLAGS) 7-search_and_replace/test_search_and_replace.c -o 7-search_and_replace/test
	@./7-search_and_replace/test
	@rm 7-search_and_replace/test

# Clean compiled files
clean:
	@echo "$(BLUE)Cleaning up...$(RESET)"
	@find . -name "test" -type f -delete
	@echo "$(GREEN)Clean complete!$(RESET)"

# Run tests with valgrind (if available)
valgrind_all:
	@echo "$(BLUE)Running tests with valgrind...$(RESET)"
	@for ex in $(EXERCISES); do \
		echo "$(BLUE)Checking: $$ex$(RESET)"; \
		$(CC) $(CFLAGS) -g $$ex/test_*.c -o $$ex/test 2>&1; \
		if [ $$? -eq 0 ]; then \
			valgrind --leak-check=full --show-leak-kinds=all ./$$ex/test 2>&1 | grep -E "(ERROR SUMMARY|definitely lost)"; \
			rm $$ex/test; \
		fi; \
	done
