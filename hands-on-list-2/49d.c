#include <sys/sem.h>

int main() {
    semctl(semget(ftok(".", 'c'), 1, 0), 0, IPC_RMID);
    semctl(semget(ftok(".", 'd'), 1, 0), 0, IPC_RMID);
    return 0;
}
