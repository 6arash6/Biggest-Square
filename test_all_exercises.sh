#!/bin/sh
# test_all_exercises.sh
# Compile and run all ex00-ex08 for C00-C13 (if present)

set -e

for mod in C{00..13}; do
  echo "\n===== $mod ====="
  for ex in ex0{0..9} ex1{0..9}; do
    dir="$mod/$ex"
    [ -d "$dir" ] || continue
    for cfile in "$dir"/*.c; do
      [ -f "$cfile" ] || continue
      echo "Compiling $cfile..."
      cc -Wall -Wextra -Werror "$cfile" -o "$dir/a.out" && echo "Running $dir/a.out:" && "$dir/a.out" || echo "(no output)"
    done
  done
done
