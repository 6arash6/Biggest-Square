#include <unistd.h>

int ft_strcmp(char *s1, char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc - 1; i++) {
        for (int j = 1; j < argc - i; j++) {
            if (ft_strcmp(argv[j], argv[j + 1]) > 0) {
                swap(&argv[j], &argv[j + 1]);
            }
        }
    }
    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];
        while (*arg) {
            write(1, arg++, 1);
        }
        write(1, "\n", 1);
    }
    return 0;
}