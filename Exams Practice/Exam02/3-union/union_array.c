#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 3)
    {
        char used[256] = {0};
        int i = 0, j;
        while (av[1][i])
        {
            unsigned char c = av[1][i];
            if (!used[c])
            {
                write(1, &c, 1);
                used[c] = 1;
            }
            i++;
        }
        i = 0;
        while (av[2][i])
        {
            unsigned char c = av[2][i];
            if (!used[c])
            {
                write(1, &c, 1);
                used[c] = 1;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}