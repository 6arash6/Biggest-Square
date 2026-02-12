#include <unistd.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];
        while (*arg) {
            write(1, arg++, 1);
        }
        write(1, "\n", 1);
    }
    return 0;
}