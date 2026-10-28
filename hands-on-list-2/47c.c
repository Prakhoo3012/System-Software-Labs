#include <stdio.h>
#include <sys/shm.h>

int main() {
    int shmid = shmget(ftok(".", 'b'), 1024, 0);
    char *data = shmat(shmid, NULL, 0);
    printf("Attached, data: %s\n", data);
    shmdt(data);
    printf("Detached\n");
    return 0;
}
