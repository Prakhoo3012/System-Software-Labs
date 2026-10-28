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
        char *my_env[] = {
            "PATH=/bin:/usr/bin",
            "CUSTOM_VAR=hello_from_lab27c",
            NULL
        };

        /* execle: same list-style args as execl, but with one
         * extra final argument - the environment array */
        execle("/bin/ls", "ls", "-R", "-l", (char *)NULL, my_env);

        perror("execle");
        _exit(EXIT_FAILURE);
    }
    else {
        wait(NULL);
        printf("[PARENT] execle-based child finished.\n");
    }

    return 0;
}