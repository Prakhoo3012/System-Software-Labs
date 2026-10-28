#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void handler(int sig) {
    printf("Caught SIGPROF\n");
    _exit(0);
}

int main() {
    struct itimerval t = {{0, 0}, {2, 0}};
    signal(SIGPROF, handler);
    setitimer(ITIMER_PROF, &t, NULL);
    while (1);
    return 0;
}
