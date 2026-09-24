#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(void) {
    int i;

    printf("Environment variables of this process:\n");

    for (i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }

    return 0;
}
