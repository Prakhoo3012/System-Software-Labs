#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(1);
        dup(fd[1]);
        close(fd[0]);
        execlp("ls", "ls", "-l", NULL);
    } else {
        close(0);
        dup(fd[0]);
        close(fd[1]);
        execlp("wc", "wc", NULL);
    }
    return 0;
}
