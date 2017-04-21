#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT "1972"
#define BACKLOG 25

// TODO: Add signal handling.

int main(int argc, char **argv) {
    struct addrinfo hints, *res, *p;
    struct sockaddr_storage their_addr;
    socklen_t sin_size;
    char s[INET_ADDRSTRLEN], buf[4096];
    int r, sockfd, new_fd, yes = 1;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((r = getaddrinfo(NULL, PORT, &hints, &res)) != 0) {
        perror(gai_strerror(r));
        exit(1);
    }

    for (p = res; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(res->ai_family, res->ai_socktype /* | SOCK_NONBLOCK */, res->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        // Allow the socket to be reused.
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
            close(sockfd);
            perror("setsockopt");
            continue;
        }

        if ((r = bind(sockfd, res->ai_addr, res->ai_addrlen)) == -1) {
            close(sockfd);
            perror("bind");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "server: could not connect\n");
        exit(1);
    }

    freeaddrinfo(res);

    if ((r = listen(sockfd, BACKLOG)) == -1) {
        perror("listen");
        exit(1);
    }

    printf("server: waiting for connections...\n");

    while (1) {
        sin_size = sizeof(their_addr);

        if ((new_fd = accept(sockfd, (struct sockaddr *) &their_addr, &sin_size)) == -1) {
            perror("accept");
            exit(1);
        }

        inet_ntop(
            their_addr.ss_family,
            &(((struct sockaddr_in *) &their_addr)->sin_addr),
            s,
            sizeof(s)
        );

        printf("server: got connection from %s\n", s);

        /*
        if (!fork()) {
            if ((r = send(new_fd, "hello world", 12, 0)) == -1) {
                perror("send");
                exit(1);
            }

            close(new_fd);
            exit(0);
        }
        */

        memset(&buf, 0, sizeof(buf));

        if ((r = recv(new_fd, buf, sizeof(buf), 0)) == -1) {
            perror("recv");
            exit(1);
        }

        write(1, buf, r);
        close(new_fd);
    }

    return 0;
}

