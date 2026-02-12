#include <stdio.h>
char *ft_str_to_upper(char *str);

int main(void)
{
    char s1[] = "Hello World!";
    char s2[] = "abc123";
    char s3[] = "";
    char s4[] = "42piscine";
    printf("%s\n", ft_str_to_upper(s1)); // HELLO WORLD!
    printf("%s\n", ft_str_to_upper(s2)); // ABC123
    printf("%s\n", ft_str_to_upper(s3)); // (empty)
    printf("%s\n", ft_str_to_upper(s4)); // 42PISCINE
    return 0;
}
