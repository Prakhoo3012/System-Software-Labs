#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction sa = {0};

    sa.sa_handler = SIG_IGN;
    sigaction(SIGINT, &sa, NULL);
    printf("SIGINT ignored for 5 seconds\n");
    sleep(5);

    sa.sa_handler = SIG_DFL;
    sigaction(SIGINT, &sa, NULL);
    printf("SIGINT reset to default for 5 seconds\n");
    sleep(5);
    return 0;
}
