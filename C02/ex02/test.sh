#!/bin/sh
# Test for ex02/ft_str_is_alpha.c
cc -Wall -Wextra -Werror ft_str_is_alpha.c main.c -o test_str_is_alpha
output=$(./test_str_is_alpha)
expected="1\n0"
echo "Test: ft_str_is_alpha("Piscine") and ft_str_is_alpha("42Piscine")"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
