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
        char *args[] = { "ls", "-R", "-l", NULL };

        execv("/bin/ls", args);

        perror("execv");
        _exit(EXIT_FAILURE);
    }
    else {
        wait(NULL);
        printf("[PARENT] execv-based child finished.\n");
    }

    return 0;
}