# ex08: ft_ten_queens_puzzle

## Objective
Write a function that solves the ten queens puzzle and returns the number of solutions.

## Function Prototype
```c
int ft_ten_queens_puzzle(void);
```

## Beginner Explanation
- Place 10 queens on a 10x10 chessboard so no two threaten each other.
- Print each solution as a sequence of column positions.
- Return the total number of solutions.

## Example
```c
ft_ten_queens_puzzle(); // prints all solutions, returns count
```

## Steps
1. Use recursion to try placing queens row by row.
2. Check if each position is safe.
3. Print each valid board.
4. Return the total count.

## Manual Testing
Use the provided main.c to test different cases.
