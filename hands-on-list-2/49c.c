#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>

int main() {
    struct sembuf op = {0, -1, 0};
    int semid = semget(ftok(".", 'd'), 1, 0);

    printf("pid %d waiting for a resource\n", getpid());
    semop(semid, &op, 1);
    printf("pid %d got a resource, free left: %d\n", getpid(), semctl(semid, 0, GETVAL));
    sleep(3);

    op.sem_op = 1;
    semop(semid, &op, 1);
    printf("pid %d released the resource\n", getpid());
    return 0;
}
