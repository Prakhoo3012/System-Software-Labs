#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGINT\n");
}

int main() {
    signal(SIGINT, handler);
    printf("Press Ctrl+C\n");
    pause();
    return 0;
}
