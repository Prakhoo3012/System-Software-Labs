#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main() {
    char buf[100];
    struct sockaddr_in addr;
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    bind(sfd, (struct sockaddr *)&addr, sizeof(addr));
    listen(sfd, 5);
    printf("Server waiting on port 8080\n");

    int cfd = accept(sfd, NULL, NULL);
    int n = read(cfd, buf, sizeof(buf));
    printf("Client says: %.*s", n, buf);
    write(cfd, "hello from server\n", 18);

    close(cfd);
    close(sfd);
    return 0;
}
