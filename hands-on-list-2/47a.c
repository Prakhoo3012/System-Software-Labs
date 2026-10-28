#include <stdio.h>
#include <string.h>
#include <sys/shm.h>

int main() {
    int shmid = shmget(ftok(".", 'b'), 1024, IPC_CREAT | 0644);
    char *data = shmat(shmid, NULL, 0);
    strcpy(data, "hello shared memory");
    printf("Written: %s\n", data);
    return 0;
}
