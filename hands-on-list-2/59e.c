#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void handler(int sig) {
    printf("Caught SIGALRM (setitimer)\n");
}

int main() {
    struct itimerval t = {{0, 0}, {2, 0}};
    signal(SIGALRM, handler);
    setitimer(ITIMER_REAL, &t, NULL);
    pause();
    return 0;
}
