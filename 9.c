#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;

    if (stat(argv[1], &fileStat) == -1) {
        fprintf(stderr, "stat() failed for '%s': %s\n", argv[1], strerror(errno));
        return 1;
    }

    printf("File: %s\n", argv[1]);
    printf("a. Inode number       : %lu\n", (unsigned long)fileStat.st_ino);
    printf("b. Hard link count    : %lu\n", (unsigned long)fileStat.st_nlink);
    printf("c. UID (owner)        : %u\n", fileStat.st_uid);
    printf("d. GID (group)        : %u\n", fileStat.st_gid);
    printf("e. Size (bytes)       : %lld\n", (long long)fileStat.st_size);
    printf("f. Preferred block sz : %ld bytes\n", (long)fileStat.st_blksize);
    printf("g. Number of blocks   : %lld (512-byte units)\n", (long long)fileStat.st_blocks);
    printf("h. Last access time   : %s", ctime(&fileStat.st_atime));
    printf("i. Last modified time : %s", ctime(&fileStat.st_mtime));
    printf("j. Last change time   : %s", ctime(&fileStat.st_ctime));

    return 0;
}