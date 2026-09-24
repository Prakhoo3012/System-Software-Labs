#include <stdio.h>
#include <fcntl.h>      // creat(), open() flags
#include <unistd.h>     // close(), write()
#include <errno.h>
#include <string.h>

int main() {
    const char *filename = "creat_test.txt";

    // creat() is equivalent to open(filename, O_CREAT|O_WRONLY|O_TRUNC, mode)
    int fd = creat(filename, 0644);

    if (fd == -1) {
        fprintf(stderr, "creat() failed: %s\n", strerror(errno));
        return 1;
    }

    printf("File descriptor value: %d\n", fd);

    close(fd);

    return 0;
}