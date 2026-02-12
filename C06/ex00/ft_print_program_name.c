#include <unistd.h>

int main(int argc, char *argv[]) {
    (void)argc;
    char *name = argv[0];
    while (*name) {
        write(1, name++, 1);
    }
    write(1, "\n", 1);
    return 0;
}