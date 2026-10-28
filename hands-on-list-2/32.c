#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    char buf[50];
    pipe(fd);

    if (fork() == 0) {
        close(fd[1]);
        int n = read(fd[0], buf, sizeof(buf));
        printf("Child received: %.*s", n, buf);
    } else {
        close(fd[0]);
        write(fd[1], "hello from parent\n", 18);
    }
    return 0;
}
