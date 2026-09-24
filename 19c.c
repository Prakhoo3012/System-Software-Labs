#include <signal.h>
#include <unistd.h>

int main() {
    raise(SIGSTOP);
    sleep(60);
    return 0;
}