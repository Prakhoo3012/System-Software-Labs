#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>   // mkfifo()
#include <sys/types.h>

int main() {
    if (mkfifo("myfifo_c", 0666) == -1) {
        fprintf(stderr, "mkfifo() failed: %s\n", strerror(errno));
        return 1;
    }
    printf("FIFO myfifo_c created\n");

    return 0;
}