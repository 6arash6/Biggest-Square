// Implement ft_params_sum according to 42 Piscine C06 standard
#include <unistd.h>

int main(int argc, char **argv)
{
    (void)argv;
    char c = '0' + argc - 1;
    write(1, &c, 1);
    write(1, "\n", 1);
    return 0;
}
