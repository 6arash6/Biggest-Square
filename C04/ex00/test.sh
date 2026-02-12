#!/bin/sh
# Test for ex00/ft_strlen.c
cc -Wall -Wextra -Werror ft_strlen.c main.c -o test_strlen
output=$(./test_strlen)
expected="9"
echo "Test: ft_strlen("Piscine42")"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
