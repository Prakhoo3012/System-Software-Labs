#include <stdio.h>
#include <sys/msg.h>

int main() {
    struct msqid_ds ds;
    int msqid = msgget(ftok(".", 'a'), 0);
    msgctl(msqid, IPC_STAT, &ds);
    printf("Old permission: %o\n", ds.msg_perm.mode);

    ds.msg_perm.mode = 0666;
    msgctl(msqid, IPC_SET, &ds);

    msgctl(msqid, IPC_STAT, &ds);
    printf("New permission: %o\n", ds.msg_perm.mode);
    return 0;
}
