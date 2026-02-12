#!/bin/sh
# Compile and run all C01 exercises (ex00-ex08)
set -e
for ex in ex0{0..9} ex1{0..9}; do
  dir="C01/$ex"
  [ -d "$dir" ] || continue
  for cfile in "$dir"/*.c; do
    [ -f "$cfile" ] || continue
    echo "Compiling $cfile..."
    cc -Wall -Wextra -Werror "$cfile" -o "$dir/a.out" && echo "Running $dir/a.out:" && "$dir/a.out" || echo "(no output)"
  done
done
