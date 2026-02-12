#include <stdio.h>
char *ft_strrev(char *str);

int main(void)
{
    char s[] = "Hello";
    printf("%s\n", ft_strrev(s)); // olleH
    char s2[] = "42Piscine";
    printf("%s\n", ft_strrev(s2)); // enicPsi24
    return 0;
}
