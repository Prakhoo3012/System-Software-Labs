#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        execlp("ls", "ls", "-R", "-l", (char *)NULL);

        perror("execlp");
        _exit(EXIT_FAILURE);
    }
    else {
        wait(NULL);
        printf("[PARENT] execlp-based child finished.\n");
    }

    return 0;
}