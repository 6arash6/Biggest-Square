// Implement ft_strcapitalize according to 42 Piscine C04 standard
char *ft_strcapitalize(char *str)
{
    int i = 0;
    int new_word = 1;
    while (str[i]) {
        if ((str[i] >= 'a' && str[i] <= 'z') && new_word) {
            str[i] -= 32;
            new_word = 0;
        } else if ((str[i] >= 'A' && str[i] <= 'Z') && !new_word) {
            str[i] += 32;
        } else if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))) {
            new_word = 1;
        } else {
            new_word = 0;
        }
        i++;
    }
    return str;
}
