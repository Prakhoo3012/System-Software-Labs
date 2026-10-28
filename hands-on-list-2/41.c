#include <stdio.h>
#include <sys/msg.h>

int main() {
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0644);
    printf("Key: 0x%x\nMessage queue id: %d\n", key, msqid);
    return 0;
}
