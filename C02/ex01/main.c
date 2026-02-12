#include <stdio.h>
char *ft_strncpy(char *dest, const char *src, unsigned int n);
int main(void) {
    char dest[100];
    const char *src = "Piscine42";
    ft_strncpy(dest, src, 4);
    printf("%s\n", dest);
    return 0;
}
