#include <stdio.h>
char *ft_strstr(const char *haystack, const char *needle);

int main(void)
{
    printf("%s\n", ft_strstr("Hello World", "World")); // World
    printf("%s\n", ft_strstr("Hello World", "42"));    // (null)
    printf("%s\n", ft_strstr("Hello", ""));            // Hello
    return 0;
}
