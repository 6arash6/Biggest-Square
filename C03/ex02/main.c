#include <stdio.h>
char *ft_strcat(char *dest, const char *src);
int main(void) {
    char dest[100] = "Piscine";
    ft_strcat(dest, "42");
    printf("%s\n", dest); // Output: Piscine42
    return 0;
}
