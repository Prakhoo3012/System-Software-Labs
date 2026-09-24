#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat st;
    lstat(argv[1], &st);

    if(S_ISREG(st.st_mode)) printf("Regular File\n");
    else if(S_ISDIR(st.st_mode)) printf("Directory\n");
    else if(S_ISLINK(st.st_mode)) printf("Sysbolic link\n");
    else if(S_ISFIFO(st.st_mode)) printf("FIFO\n");
    else if(S_ISCHR(st.st_mode)) printf("Character device\n");
    else if(S_ISBLK(st.st_mode)) printf("Block device\n");
    else if(S_ISSOCK(st.st_mode)) printf("Socket\n");

    return 0;
}