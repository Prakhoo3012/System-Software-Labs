#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    printf("Priority (nice value): %d\n", getpriority(PRIO_PROCESS, getpid()));
    return 0;
}
