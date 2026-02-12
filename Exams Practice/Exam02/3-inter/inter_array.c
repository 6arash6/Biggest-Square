#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 3)
    {
        char used[256] = {0};
        int i = 0;
        while (av[1][i])
        {
            char c = av[1][i];
            if (!used[(unsigned char)c])
            {
                int j = 0;
                while (av[2][j])
                {
                    if (av[2][j] == c)
                    {
                        write(1, &c, 1);
                        used[(unsigned char)c] = 1;
                        break;
                    }
                    j++;
                }
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}