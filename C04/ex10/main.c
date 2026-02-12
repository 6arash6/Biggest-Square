#include <stdio.h>
char *ft_strcapitalize(char *str);

int main(void)
{
    char s1[] = "hello world! 42piscine";
    char s2[] = "abc123 DEF";
    char s3[] = "";
    char s4[] = "42piscine is awesome";
    printf("%s\n", ft_strcapitalize(s1)); // Hello World! 42Piscine
    printf("%s\n", ft_strcapitalize(s2)); // Abc123 Def
    printf("%s\n", ft_strcapitalize(s3)); // (empty)
    printf("%s\n", ft_strcapitalize(s4)); // 42Piscine Is Awesome
    return 0;
}
