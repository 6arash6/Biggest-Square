#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        char *p = av[1];
        char *last = 0;
        while (*p)
        {
            while (*p == ' ' || *p == '\t')
                p++;
            if (*p)
                last = p;
            while (*p && *p != ' ' && *p != '\t')
                p++;
        }
        if (last)
        {
            while (*last && *last != ' ' && *last != '\t')
                write(1, last++, 1);
        }
    }
    write(1, "\n", 1);
    return 0;
}