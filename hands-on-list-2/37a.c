#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    mkfifo("files/fifo37", 0644);
    int fd = open("files/fifo37", O_WRONLY);
    write(fd, "hello through fifo\n", 19);
    close(fd);
    return 0;
}
