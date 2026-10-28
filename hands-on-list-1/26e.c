#include <unistd.h>

int main() {
    char *argv[] = { "ls", "-Rl", NULL };
    execvp("ls", argv);
    return 0;
}
