#include <stdio.h>
char *ft_strcpy(char *dest, const char *src);

int main(void)
{
    char dest[10];
    printf("%s\n", ft_strcpy(dest, "Hello")); // Hello
    char dest2[5];
    printf("%s\n", ft_strcpy(dest2, "42")); // 42
    return 0;
}
