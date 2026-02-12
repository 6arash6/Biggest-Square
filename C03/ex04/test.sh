#!/bin/sh
# Test for ex04/ft_strrchr.c
cc -Wall -Wextra -Werror ft_strrchr.c main.c -o test_strrchr
output=$(./test_strrchr)
expected="ine42"
echo "Test: ft_strrchr("Piscine42", 'i')"
echo "Expected: $expected"
echo "Actual:   $output"
if [ "$output" = "$expected" ]; then
  echo "PASS"
else
  echo "FAIL"
fi
