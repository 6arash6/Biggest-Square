#include "bsq.h"

char    *ft_realloc(char *str, int old_size, int new_size)
{
    char    *new_str;
    int        i;

    new_str = (char *)malloc(sizeof(char) * new_size);
    if (!new_str)
        return (NULL);
    i = 0;
    while (i < old_size)
    {
        new_str[i] = str[i];
        i++;
    }
    if (str)
        free(str);
    return (new_str);
}

int    ft_atoi(char *str)
{
    int    result;
    int    sign;
    int    i;

    result = 0;
    sign = 1;
    i = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
        || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

int    ft_isnumber(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int    ft_strlen(char *str)
{
    int    len;

    len = 0;
    if (!str)
        return (0);
    while (str[len])
        len++;
    return (len);
}

void    ft_putstr(char *str)
{
    int    i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_puterror(char *str)
{
    int    i;

    i = 0;
    while (str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
}
