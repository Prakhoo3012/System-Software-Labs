#include <fcntl.h>
#include <unistd.h>

int main() {

    int fd1 = open("lab11b.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    int fd2 = open("lab11b_other.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    dup2(fd1, fd2);

    write(fd1, "from fd1\n", 9);
    write(fd2, "from fd2\n", 9);

    close(fd1);
    close(fd2);
    return 0;
}