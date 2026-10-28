#include <stdio.h>
#include <sys/sem.h>

union semun {
    int val;
};

int main() {
    union semun arg;
    int semid = semget(ftok(".", 'c'), 1, IPC_CREAT | 0644);
    arg.val = 1;
    semctl(semid, 0, SETVAL, arg);
    printf("Binary semaphore id: %d, value: %d\n", semid, semctl(semid, 0, GETVAL));
    return 0;
}
