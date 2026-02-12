#include <stdio.h>
char *ft_str_to_lower(char *str);

int main(void)
{
    char s1[] = "HELLO WORLD!";
    char s2[] = "ABC123";
    char s3[] = "";
    char s4[] = "42PISCINE";
    printf("%s\n", ft_str_to_lower(s1)); // hello world!
    printf("%s\n", ft_str_to_lower(s2)); // abc123
    printf("%s\n", ft_str_to_lower(s3)); // (empty)
    printf("%s\n", ft_str_to_lower(s4)); // 42piscine
    return 0;
}
