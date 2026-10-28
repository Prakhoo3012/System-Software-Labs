#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *fp = fopen("original.txt", "w");

    fprintf(fp, "This is the original file\n");
    fclose(fp);

    link("original.txt", "hard_c.txt");

    return 0;
}