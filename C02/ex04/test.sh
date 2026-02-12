#!/bin/sh
# Test for ex04/ft_str_is_lowercase.c
cc -Wall -Wextra -Werror ft_str_is_lowercase.c main.c -o test_str_is_lowercase
output=$(./test_str_is_lowercase)
expected="1\n0"
echo "Test: ft_str_is_lowercase("piscine") and ft_str_is_lowercase("Piscine")"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
