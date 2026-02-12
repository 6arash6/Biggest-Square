#!/bin/sh
# Test for ex01/ft_strncpy.c
cc -Wall -Wextra -Werror ft_strncpy.c main.c -o test_strncpy
output=$(./test_strncpy)
expected="Pisc"
echo "Test: ft_strncpy(dest, "Piscine42", 4)"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
