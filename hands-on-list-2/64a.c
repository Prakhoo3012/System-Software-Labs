#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGSTOP\n");
}

int main() {
    if (signal(SIGSTOP, handler) == SIG_ERR)
        printf("Cannot set handler for SIGSTOP\n");
    printf("pid %d waiting for SIGSTOP\n", getpid());
    while (1)
        sleep(1);
    return 0;
}
