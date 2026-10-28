#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd[2];
    pipe(fd);
    printf("Max open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Pipe size: %d\n", fcntl(fd[0], F_GETPIPE_SZ));
    return 0;
}
