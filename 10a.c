#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd = open("lab10.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    write(fd, "AAAAAAAAAA", 10);
    off_t pos = lseek(fd, 10, SEEK_CUR);
    printf("lseek returned: %ld\n", pos);
    write(fd, "BBBBBBBBBB", 10);

    close(fd);
    return 0;
}