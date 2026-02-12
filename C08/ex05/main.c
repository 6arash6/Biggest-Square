#include <stdio.h>
char *ft_strcat(char *dest, const char *src);

int main(void)
{
    char dest[20] = "Hello";
    printf("%s\n", ft_strcat(dest, "World")); // HelloWorld
    char dest2[20] = "42";
    printf("%s\n", ft_strcat(dest2, "Piscine")); // 42Piscine
    return 0;
}
