#include <stdio.h>
unsigned int ft_strlcat(char *dest, const char *src, unsigned int size);
int main(void) {
    char dest[100] = "Piscine";
    unsigned int result = ft_strlcat(dest, "42", 100);
    printf("%s\n", dest); // Output: Piscine42
    printf("%u\n", result); // Output: 9
    return 0;
}
