#include <sys/stat.h>

int main() {
    mkfifo("files/fifo36e", 0644);
    return 0;
}
