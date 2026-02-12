#include <stdio.h>
#include <stdlib.h>
char *ft_strjoin(const char *s1, const char *s2);

int main(void)
{
    char *s = ft_strjoin("Hello", "World");
    printf("%s\n", s);
    free(s);
    char *s2 = ft_strjoin("", "42");
    printf("%s\n", s2);
    free(s2);
    return 0;
}
