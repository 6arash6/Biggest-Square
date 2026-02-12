#include <stdio.h>
char *ft_strncpy(char *dest, const char *src, unsigned int n);

int main(void)
{
    char dest[10];
    printf("%s\n", ft_strncpy(dest, "Hello", 10)); // Hello
    char dest2[5];
    printf("%s\n", ft_strncpy(dest2, "42", 5)); // 42
    return 0;
}
