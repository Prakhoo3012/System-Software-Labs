#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/select.h>

int main() {
    char buf[50];
    mkfifo("files/fifo39", 0644);
    int fd = open("files/fifo39", O_RDONLY | O_NONBLOCK);

    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);
    struct timeval tv = {10, 0};

    if (select(fd + 1, &rfds, NULL, NULL, &tv) > 0) {
        int n = read(fd, buf, sizeof(buf));
        printf("Data available: %.*s", n, buf);
    } else
        printf("No data within 10 seconds\n");
    return 0;
}
