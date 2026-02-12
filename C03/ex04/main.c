#include <stdio.h>
char *ft_strrchr(const char *s, int c);
int main(void) {
    const char *s = "Piscine42";
    char *result = ft_strrchr(s, 'i');
    printf("%s\n", result); // Output: ine42
    return 0;
}
