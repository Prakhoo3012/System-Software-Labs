#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd[5];

    for (int i = 0; i < 5; i++) {
        char file[20];

        sprintf(file, "file%d.txt", i + 1);

        fd[i] = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);

        if (fd[i] == -1) {
            perror("open failed");
            return 1;
        }

        printf("%s opened with fd = %d\n", file, fd[i]);
    }

    printf("\nPID = %d\n", getpid());
    printf("Run: ls -l /proc/%d/fd\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
}