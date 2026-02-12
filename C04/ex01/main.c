#include <stdio.h>
char *ft_strcpy(char *dest, const char *src);
int main(void) {
    char dest[100];
    ft_strcpy(dest, "Piscine42");
    printf("%s\n", dest);
    return 0;
}
