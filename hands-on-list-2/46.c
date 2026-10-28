#include <stdio.h>
#include <sys/msg.h>

int main() {
    int msqid = msgget(ftok(".", 'a'), 0);
    msgctl(msqid, IPC_RMID, NULL);
    return 0;
}
