#!/bin/sh
# Test for ex05/ft_str_is_uppercase.c
cc -Wall -Wextra -Werror ft_str_is_uppercase.c main.c -o test_str_is_uppercase
output=$(./test_str_is_uppercase)
expected="1\n0"
echo "Test: ft_str_is_uppercase("PISCINE") and ft_str_is_uppercase("Piscine")"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
