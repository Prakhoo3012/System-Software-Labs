#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {
        printf("Child %d, parent before kill: %d\n", getpid(), getppid());
        kill(getppid(), SIGKILL);
        sleep(1);
        printf("Child %d, parent after kill: %d\n", getpid(), getppid());
    } else {
        printf("Parent %d sleeping\n", getpid());
        sleep(10);
    }
    return 0;
}
