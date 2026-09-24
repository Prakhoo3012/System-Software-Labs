#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    pid_t pid = getpid();
    printf("My pid: %d\n", pid);
    printf("Check /proc/%d/ in another terminal now.\n", pid);

    while (1) {
        printf("Hello from: %d\n", pid);
        fflush(stdout);
        sleep(5);
    }

    return 0;
}