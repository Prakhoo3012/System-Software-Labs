#include <stdio.h>
#include <pthread.h>

void *run(void *arg) {
    printf("Thread ID: %lu\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t t[3];
    for (int i = 0; i < 3; i++)
        pthread_create(&t[i], NULL, run, NULL);
    for (int i = 0; i < 3; i++)
        pthread_join(t[i], NULL);
    return 0;
}
