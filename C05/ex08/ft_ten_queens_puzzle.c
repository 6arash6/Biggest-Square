// Implement ft_ten_queens_puzzle according to 42 Piscine C05 standard
#include <stdio.h>

int is_safe(int *board, int row, int col)
{
    for (int i = 0; i < row; i++) {
        if (board[i] == col ||
            board[i] - i == col - row ||
            board[i] + i == col + row)
            return 0;
    }
    return 1;
}

void print_board(int *board)
{
    for (int i = 0; i < 10; i++)
        printf("%d", board[i]);
    printf("\n");
}

int solve(int *board, int row)
{
    int count = 0;
    if (row == 10) {
        print_board(board);
        return 1;
    }
    for (int col = 0; col < 10; col++) {
        if (is_safe(board, row, col)) {
            board[row] = col;
            count += solve(board, row + 1);
        }
    }
    return count;
}

int ft_ten_queens_puzzle(void)
{
    int board[10];
    return solve(board, 0);
}
