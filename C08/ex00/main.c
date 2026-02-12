#include <stdio.h>
#include <stdlib.h>
char *ft_create_array(unsigned int size, char c);

int main(void)
{
    char *arr = ft_create_array(5, 'A');
    printf("%s\n", arr);
    free(arr);
    char *arr2 = ft_create_array(0, 'B');
    printf("%s\n", arr2);
    free(arr2);
    return 0;
}
