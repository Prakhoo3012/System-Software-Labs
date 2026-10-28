#include <stdio.h>
#include <time.h>
#include <sys/msg.h>

int main() {
    struct msqid_ds ds;
    int msqid = msgget(ftok(".", 'a'), 0);
    msgctl(msqid, IPC_STAT, &ds);

    printf("Access permission: %o\n", ds.msg_perm.mode);
    printf("UID: %d, GID: %d\n", ds.msg_perm.uid, ds.msg_perm.gid);
    printf("Last msg sent: %s", ctime(&ds.msg_stime));
    printf("Last msg received: %s", ctime(&ds.msg_rtime));
    printf("Last change: %s", ctime(&ds.msg_ctime));
    printf("Current size of queue (bytes): %lu\n", ds.__msg_cbytes);
    printf("Number of messages: %lu\n", ds.msg_qnum);
    printf("Max bytes allowed: %lu\n", ds.msg_qbytes);
    printf("PID of last msgsnd: %d, msgrcv: %d\n", ds.msg_lspid, ds.msg_lrpid);
    return 0;
}
