#!/bin/sh
# Test for ex01/ft_strncmp.c
cc -Wall -Wextra -Werror ft_strncmp.c main.c -o test_strncmp
output=$(./test_strncmp)
expected="0\n6\n-6"
echo "Test: ft_strncmp("Piscine", "Piscine", 4), ft_strncmp("Piscine", "42", 2), ft_strncmp("42", "Piscine", 2)"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
