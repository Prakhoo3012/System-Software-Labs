#include <unistd.h>

int main() {
    int p1[2], p2[2];
    pipe(p1);
    pipe(p2);

    if (fork() == 0) {
        dup2(p1[1], 1);
        close(p1[0]); close(p2[0]); close(p2[1]);
        execlp("ls", "ls", "-l", NULL);
    }
    if (fork() == 0) {
        dup2(p1[0], 0);
        dup2(p2[1], 1);
        close(p1[1]); close(p2[0]);
        execlp("grep", "grep", "^d", NULL);
    }
    dup2(p2[0], 0);
    close(p1[0]); close(p1[1]); close(p2[1]);
    execlp("wc", "wc", NULL);
    return 0;
}
