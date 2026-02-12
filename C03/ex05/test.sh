#!/bin/sh
# Test for ex05/ft_strstr.c
cc -Wall -Wextra -Werror ft_strstr.c main.c -o test_strstr
output=$(./test_strstr)
expected="42"
echo "Test: ft_strstr("Piscine42", "42")"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
