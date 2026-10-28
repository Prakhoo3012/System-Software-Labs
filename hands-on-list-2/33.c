#include <stdio.h>
#include <unistd.h>

int main() {
    int p2c[2], c2p[2];
    char buf[50];
    pipe(p2c);
    pipe(c2p);

    if (fork() == 0) {
        close(p2c[1]);
        close(c2p[0]);
        int n = read(p2c[0], buf, sizeof(buf));
        printf("Child received: %.*s", n, buf);
        write(c2p[1], "hello from child\n", 17);
    } else {
        close(p2c[0]);
        close(c2p[1]);
        write(p2c[1], "hello from parent\n", 18);
        int n = read(c2p[0], buf, sizeof(buf));
        printf("Parent received: %.*s", n, buf);
    }
    return 0;
}
