#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGALRM (alarm)\n");
}

int main() {
    signal(SIGALRM, handler);
    alarm(2);
    pause();
    return 0;
}
