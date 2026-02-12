#!/bin/sh
# Test for ex02/ft_strcat.c
cc -Wall -Wextra -Werror ft_strcat.c main.c -o test_strcat
output=$(./test_strcat)
expected="Piscine42"
echo "Test: ft_strcat("Piscine", "42")"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
