#include <unistd.h>

int main(int argc, char *argv[]) {
    for (int i = argc - 1; i > 0; i--) {
        char *arg = argv[i];
        while (*arg) {
            write(1, arg++, 1);
        }
        write(1, "\n", 1);
    }
    return 0;
}