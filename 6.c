#include <stdio.h>
#include <unistd.h>

int main() {
    char buffer[128];
    int n;

    while ((n = read(0, buffer, 128)) > 0) {
        if (write(1, buffer, n) == -1) {
            perror("write failed");
            return 1;
        }
    }

    if (n == -1) {
        perror("read failed");
        return 1;
    }

    return 0;
}