#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char buf[50];
    mkfifo("files/fifo37", 0644);
    int fd = open("files/fifo37", O_RDONLY);
    int n = read(fd, buf, sizeof(buf));
    printf("Received: %.*s", n, buf);
    close(fd);
    return 0;
}
