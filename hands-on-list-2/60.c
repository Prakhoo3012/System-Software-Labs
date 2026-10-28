#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    signal(SIGINT, SIG_IGN);
    printf("SIGINT ignored for 5 seconds\n");
    sleep(5);

    signal(SIGINT, SIG_DFL);
    printf("SIGINT reset to default for 5 seconds\n");
    sleep(5);
    return 0;
}
