#!/bin/sh
# Test for ex03/ft_str_is_numeric.c
cc -Wall -Wextra -Werror ft_str_is_numeric.c main.c -o test_str_is_numeric
output=$(./test_str_is_numeric)
expected="1\n0"
echo "Test: ft_str_is_numeric("123456") and ft_str_is_numeric("42Piscine")"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
