#include <unistd.h>

int main() {
    char *argv[] = { "ls", "-Rl", NULL };
    execv("/bin/ls", argv);
    return 0;
}
