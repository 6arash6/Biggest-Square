#include <stdio.h>
void ft_str_non_printable(const char *str);

int main(void)
{
    ft_str_non_printable("Hello\nWorld"); // Hello\0aWorld
    ft_str_non_printable("abc\t123");    // abc\09 123
    ft_str_non_printable("");             // (empty)
    ft_str_non_printable("42Piscine");    // 42Piscine
    return 0;
}
