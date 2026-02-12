/*
** ex06 - ft_strlen.c
** Return the length of a string.
*/
int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}
