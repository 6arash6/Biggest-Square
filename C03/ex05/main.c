#include <stdio.h>
char *ft_strstr(const char *haystack, const char *needle);
int main(void) {
    const char *haystack = "Piscine42";
    const char *needle = "42";
    char *result = ft_strstr(haystack, needle);
    printf("%s\n", result); // Output: 42
    return 0;
}
