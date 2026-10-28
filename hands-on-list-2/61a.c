#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGSEGV\n");
    _exit(1);
}

int main() {
    struct sigaction sa = {0};
    sa.sa_handler = handler;
    sigaction(SIGSEGV, &sa, NULL);

    int *p = NULL;
    *p = 10;
    return 0;
}
