// Implement ft_print_rev_params according to 42 Piscine C06 standard
#include <unistd.h>

int main(int argc, char **argv)
{
    int i, j;
    for (i = argc - 1; i > 0; i--) {
        j = 0;
        while (argv[i][j]) {
            write(1, &argv[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
    }
    return 0;
}
