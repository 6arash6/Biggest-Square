#include <stdio.h>
#include <stdlib.h>
char *ft_itoa(int n);

int main(void)
{
    char *s = ft_itoa(42);
    printf("%s\n", s);
    free(s);
    char *s2 = ft_itoa(-42);
    printf("%s\n", s2);
    free(s2);
    return 0;
}
