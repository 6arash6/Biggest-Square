#include <stdio.h>
#include <stdlib.h>
char *ft_strtrim(const char *str);

int main(void)
{
    char *s = ft_strtrim("  Hello World  ");
    printf("%s\n", s);
    free(s);
    char *s2 = ft_strtrim("\t42Piscine\n");
    printf("%s\n", s2);
    free(s2);
    return 0;
}
