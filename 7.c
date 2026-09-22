#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int src = open("lab7.txt", O_RDONLY);
    int dest = open("lab7_cp.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    char buffer[4096];
    int n;

    while ((n = read(src, buffer, 4096)) > 0) {
        write(dest, buffer, n);
    }

    close(src);
    close(dest);

    printf("File copied successfully\n");

    return 0;
}