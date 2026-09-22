#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUF_SIZE 32

int main(int argc, char *argv[])
{
    int fd = open("ticket.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    write(fd, "100\n", 4);
    close(fd);
    return 0;
}