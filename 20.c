#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0)
        printf("Child pid: %d\n", getpid());
    else
        printf("Parent pid: %d, child pid: %d\n", getpid(), pid);

    return 0;
}