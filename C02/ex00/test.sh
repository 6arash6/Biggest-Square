#!/bin/sh
# Test for ex00/ft_strcpy.c
cc -Wall -Wextra -Werror ft_strcpy.c main.c -o test_strcpy
output=$(./test_strcpy)
expected="Piscine42"
echo "Test: ft_strcpy(dest, "Piscine42")"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
