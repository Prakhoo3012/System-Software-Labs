#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit r;
    int res[] = {RLIMIT_CPU, RLIMIT_FSIZE, RLIMIT_DATA, RLIMIT_STACK, RLIMIT_CORE,
                 RLIMIT_NOFILE, RLIMIT_NPROC, RLIMIT_AS, RLIMIT_MEMLOCK};
    char *names[] = {"CPU", "FSIZE", "DATA", "STACK", "CORE",
                     "NOFILE", "NPROC", "AS", "MEMLOCK"};

    for (int i = 0; i < 9; i++) {
        getrlimit(res[i], &r);
        printf("%-8s soft: %lu, hard: %lu\n", names[i], r.rlim_cur, r.rlim_max);
    }
    return 0;
}
