#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    char buf[100];
    struct sockaddr_in addr;
    int sfd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(8080);

    connect(sfd, (struct sockaddr *)&addr, sizeof(addr));
    write(sfd, "hello from client\n", 18);
    int n = read(sfd, buf, sizeof(buf));
    printf("Server says: %.*s", n, buf);

    close(sfd);
    return 0;
}
