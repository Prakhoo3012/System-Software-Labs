#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("lab12.txt", O_RDWR | O_CREAT, 0644);
    int flags = fcntl(fd, F_GETFL);

    if((flags & O_ACCMODE) == O_RDONLY) printf("Read only\n");
    else if((flags & O_ACCMODE) == O_WRONLY) printf("Write only\n");
    else if((flags & O_ACCMODE) == O_RDWR) printf("Read Write\n");

    close(fd);
    return 0;
}