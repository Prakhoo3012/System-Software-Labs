#include <stdio.h>
#include <string.h>
#include <sys/shm.h>

int main() {
    int shmid = shmget(ftok(".", 'b'), 1024, 0);
    char *data = shmat(shmid, NULL, SHM_RDONLY);
    printf("Read: %s\n", data);
    printf("Trying to overwrite...\n");
    fflush(stdout);
    strcpy(data, "overwrite");
    printf("Overwritten: %s\n", data);
    return 0;
}
