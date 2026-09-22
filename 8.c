#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE 1024

int main() {
    FILE *fp = fopen("lab_8.txt", "r");
    char line[100];

    while(fgets(line, 100, fp)!= NULL) {
        printf("%s", line);
    }

    fclose(fp);

    return 0;
}