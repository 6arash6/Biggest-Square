#include <stdio.h>
char *ft_strncat(char *dest, const char *src, unsigned int n);

int main(void)
{
    char dest[20] = "Hello";
    printf("%s\n", ft_strncat(dest, "World", 3)); // HelloWor
    char dest2[20] = "42";
    printf("%s\n", ft_strncat(dest2, "Piscine", 2)); // 42Pi
    return 0;
}
