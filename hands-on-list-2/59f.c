#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void handler(int sig) {
    printf("Caught SIGVTALRM\n");
    _exit(0);
}

int main() {
    struct itimerval t = {{0, 0}, {2, 0}};
    signal(SIGVTALRM, handler);
    setitimer(ITIMER_VIRTUAL, &t, NULL);
    while (1);
    return 0;
}
