#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGFPE\n");
    _exit(1);
}

int main() {
    signal(SIGFPE, handler);
    int a = 10, b = 0;
    printf("%d\n", a / b);
    return 0;
}
