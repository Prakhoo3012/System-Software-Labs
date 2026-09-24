#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
   int setup = open("lab_4.txt", O_CREAT, 0644);
   close(setup);

   int fd = open("lab_4.txt", O_RDWR);
   printf("Opened existing file, fd = %d \n", fd);
   close(fd);

   int fd2 = open("lab_4.txt", O_CREAT | O_EXCL, 0644);
   printf("opened with O_CREAT | O_EXCL on existing file. fd = %d\n", fd2);
   perror("O_EXCL result");

    return 0;
}