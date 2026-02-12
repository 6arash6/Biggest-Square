#!/bin/sh
# Test script for do-op

gcc -Wall -Wextra -Werror main.c -o do-op
./do-op 42 + 21
./do-op 25 / 0
./do-op 25 % 0
./do-op 1 p 1
rm -f do-op
