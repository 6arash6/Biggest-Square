// Implement ft_strlcat according to 42 Piscine C03 standard
unsigned int ft_strlcat(char *dest, const char *src, unsigned int size)
{
    unsigned int i = 0, j = 0, dest_len = 0, src_len = 0;
    while (dest[dest_len]) dest_len++;
    while (src[src_len]) src_len++;
    if (size <= dest_len)
        return size + src_len;
    while (src[j] && dest_len + j < size - 1) {
        dest[dest_len + j] = src[j];
        j++;
    }
    dest[dest_len + j] = '\0';
    return dest_len + src_len;
}
