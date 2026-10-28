#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGSEGV\n");
    _exit(1);
}

int main() {
    signal(SIGSEGV, handler);
    int *p = NULL;
    *p = 10;
    return 0;
}
