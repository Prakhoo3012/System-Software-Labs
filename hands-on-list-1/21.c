#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("lab21.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    pid_t pid = fork();

    if (pid == 0)
        write(fd, "child\n", 6);
    else
        write(fd, "parent\n", 7);

    close(fd);
    return 0;
}