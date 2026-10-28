#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("ticket.txt", O_RDWR);

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    fcntl(fd, F_SETLKW, &lock);

    char buf[16];
    int n = read(fd, buf, sizeof(buf) - 1);
    buf[n] = '\0';
    int ticket = atoi(buf) + 1;

    printf("New ticket number: %d\n", ticket);

    lseek(fd, 0, SEEK_SET);
    n = sprintf(buf, "%d\n", ticket);
    write(fd, buf, n);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    return 0;
}