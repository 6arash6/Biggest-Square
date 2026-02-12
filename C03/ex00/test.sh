#!/bin/sh
# Test for ex00/ft_strcmp.c
cc -Wall -Wextra -Werror ft_strcmp.c main.c -o test_strcmp
output=$(./test_strcmp)
expected="0\n1\n-1"
echo "Test: ft_strcmp("Piscine", "Piscine"), ft_strcmp("Piscine", "42"), ft_strcmp("42", "Piscine")"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
