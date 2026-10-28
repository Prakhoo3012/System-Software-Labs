#include <stdio.h>
#include <sys/msg.h>

struct msg {
    long type;
    char text[50];
};

int main() {
    struct msg m;
    int msqid = msgget(ftok(".", 'a'), 0);
    msgrcv(msqid, &m, sizeof(m.text), 0, 0);
    printf("Received (type %ld): %s\n", m.type, m.text);
    return 0;
}
