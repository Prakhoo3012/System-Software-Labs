#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGFPE\n");
    _exit(1);
}

int main() {
    struct sigaction sa = {0};
    sa.sa_handler = handler;
    sigaction(SIGFPE, &sa, NULL);

    int a = 10, b = 0;
    printf("%d\n", a / b);
    return 0;
}
