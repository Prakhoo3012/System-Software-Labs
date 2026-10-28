#include <stdio.h>
#include <sys/shm.h>

int main() {
    int shmid = shmget(ftok(".", 'b'), 1024, 0);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
