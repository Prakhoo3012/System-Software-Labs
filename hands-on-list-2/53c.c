#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void handler(int sig) {
    printf("Timer expired\n");
}

int main() {
    struct itimerval t;
    signal(SIGPROF, handler);

    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 10;
    t.it_interval.tv_sec = 10;
    t.it_interval.tv_usec = 10;
    setitimer(ITIMER_PROF, &t, NULL);

    while (1);
    return 0;
}
