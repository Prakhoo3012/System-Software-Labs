#include <sys/stat.h>

int main() {
    mknod("files/fifo36d", S_IFIFO | 0644, 0);
    return 0;
}
