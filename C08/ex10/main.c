#include <stdio.h>
unsigned int ft_strlcat(char *dest, const char *src, unsigned int size);

int main(void)
{
    char dest[10] = "Hello";
    unsigned int len;
    len = ft_strlcat(dest, "World", 10);
    printf("dest: %s, len: %u\n", dest, len); // dest: HelloWorl, len: 10
    char dest2[5] = "42";
    len = ft_strlcat(dest2, "Piscine", 5);
    printf("dest: %s, len: %u\n", dest2, len); // dest: 42Pis, len: 8
    char dest3[10] = "";
    len = ft_strlcat(dest3, "abc", 10);
    printf("dest: %s, len: %u\n", dest3, len); // dest: abc, len: 3
    return 0;
}
