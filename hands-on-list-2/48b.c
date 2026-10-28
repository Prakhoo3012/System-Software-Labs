#include <stdio.h>
#include <sys/sem.h>

union semun {
    int val;
};

int main() {
    union semun arg;
    int semid = semget(ftok(".", 'd'), 1, IPC_CREAT | 0644);
    arg.val = 2;
    semctl(semid, 0, SETVAL, arg);
    printf("Counting semaphore id: %d, value: %d\n", semid, semctl(semid, 0, GETVAL));
    return 0;
}
