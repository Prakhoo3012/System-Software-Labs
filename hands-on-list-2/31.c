#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    char buf[50];
    pipe(fd);
    write(fd[1], "hello through pipe\n", 19);
    int n = read(fd[0], buf, sizeof(buf));
    write(1, buf, n);
    return 0;
}
