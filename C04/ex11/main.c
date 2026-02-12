#include <stdio.h>
unsigned int ft_strlcpy(char *dest, const char *src, unsigned int size);

int main(void)
{
    char dest[10];
    unsigned int len;
    len = ft_strlcpy(dest, "Hello", 10);
    printf("dest: %s, len: %u\n", dest, len); // dest: Hello, len: 5
    len = ft_strlcpy(dest, "42Piscine", 5);
    printf("dest: %s, len: %u\n", dest, len); // dest: 42Pi, len: 9
    len = ft_strlcpy(dest, "", 10);
    printf("dest: %s, len: %u\n", dest, len); // dest: (empty), len: 0
    return 0;
}
