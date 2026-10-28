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
        execl("/bin/ls", "ls", "-R", "-l", (char *)NULL);

        perror("execl");
        _exit(EXIT_FAILURE);
    }
    else {
        wait(NULL);
        printf("[PARENT] execl-based child finished.\n");
    }

    return 0;
}