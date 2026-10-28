#include <stdio.h>
#include <unistd.h>
#include <x86intrin.h>

int main() {
    unsigned long long start = __rdtsc();
    for (int i = 0; i < 100; i++)
        getppid();
    unsigned long long end = __rdtsc();
    printf("Cycles for 100 getppid(): %llu\n", end - start);
    return 0;
}
