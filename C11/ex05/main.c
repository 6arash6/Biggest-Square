#include <unistd.h>
#include <stdlib.h>

int ft_atoi(char *str) {
    int res = 0, sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13)) str++;
    if (*str == '-') sign = -1, str++;
    else if (*str == '+') str++;
    while (*str >= '0' && *str <= '9') res = res * 10 + (*str++ - '0');
    return res * sign;
}

void ft_putnbr(int n) {
    char c;
    if (n < 0) { write(1, "-", 1); n = -n; }
    if (n > 9) ft_putnbr(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}

void ft_putstr(char *s) { while (*s) write(1, s++, 1); }

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div(int a, int b) { return b ? a / b : 0; }
int mod(int a, int b) { return b ? a % b : 0; }

int main(int argc, char **argv) {
    int (*ops[5])(int, int) = {add, sub, div, mul, mod};
    char *op = argv[2];
    if (argc != 4) return 0;
    int a = ft_atoi(argv[1]), b = ft_atoi(argv[3]);
    if (*op == '+') ft_putnbr(ops[0](a, b));
    else if (*op == '-') ft_putnbr(ops[1](a, b));
    else if (*op == '/') {
        if (b == 0) ft_putstr("Stop : division by zero\n");
        else ft_putnbr(ops[2](a, b));
    }
    else if (*op == '*') ft_putnbr(ops[3](a, b));
    else if (*op == '%') {
        if (b == 0) ft_putstr("Stop : modulo by zero\n");
        else ft_putnbr(ops[4](a, b));
    }
    else ft_putnbr(0);
    write(1, "\n", 1);
    return 0;
}
