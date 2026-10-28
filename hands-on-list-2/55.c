#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit r;
    getrlimit(RLIMIT_NOFILE, &r);
    printf("Before: soft %lu, hard %lu\n", r.rlim_cur, r.rlim_max);

    r.rlim_cur = 100;
    setrlimit(RLIMIT_NOFILE, &r);

    getrlimit(RLIMIT_NOFILE, &r);
    printf("After:  soft %lu, hard %lu\n", r.rlim_cur, r.rlim_max);
    return 0;
}
