#include <stdio.h>
char *ft_strcpy(char *dest, const char *src);
int main(void) {
    char dest[100];
    const char *src = "Piscine42";
    ft_strcpy(dest, src);
    printf("%s\n", dest);
    return 0;
}
