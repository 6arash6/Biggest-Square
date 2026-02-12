#include <stdio.h>
#include <stdlib.h>
char *ft_strdup(const char *src);

int main(void)
{
    char *s1 = ft_strdup("Hello");
    printf("%s\n", s1);
    free(s1);
    char *s2 = ft_strdup("");
    printf("%s\n", s2);
    free(s2);
    return 0;
}
