#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Max length of exec arguments: %ld\n", sysconf(_SC_ARG_MAX));
    printf("Max processes per user: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("Clock ticks per second: %ld\n", sysconf(_SC_CLK_TCK));
    printf("Max open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Page size: %ld\n", sysconf(_SC_PAGESIZE));
    printf("Total physical pages: %ld\n", sysconf(_SC_PHYS_PAGES));
    printf("Available physical pages: %ld\n", sysconf(_SC_AVPHYS_PAGES));
    return 0;
}
