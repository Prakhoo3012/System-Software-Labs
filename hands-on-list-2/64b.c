#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    kill(atoi(argv[1]), SIGSTOP);
    printf("Sent SIGSTOP to %s\n", argv[1]);
    return 0;
}
