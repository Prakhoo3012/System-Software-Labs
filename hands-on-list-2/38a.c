#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char buf[50];
    mkfifo("files/fifo38_1", 0644);
    mkfifo("files/fifo38_2", 0644);
    int wfd = open("files/fifo38_1", O_WRONLY);
    int rfd = open("files/fifo38_2", O_RDONLY);

    write(wfd, "hello from 38a\n", 15);
    int n = read(rfd, buf, sizeof(buf));
    printf("38a received: %.*s", n, buf);
    return 0;
}
