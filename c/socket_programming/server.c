#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT "1972"
#define BACKLOG 25

// TODO: Add signal handling.

int main(int argc, char **argv) {
    fd_set master;
    fd_set readfds;
    struct addrinfo hints, *res, *p;
    struct sockaddr_storage their_addr;
    socklen_t sin_size;
    char s[INET_ADDRSTRLEN], buf[4096];
    int r, sockfd, new_fd,
        fdmax, i, yes = 1;

    memset(&buf, 0, sizeof(buf));
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
        exit(2);
    }

    freeaddrinfo(res);

    if ((r = listen(sockfd, BACKLOG)) == -1) {
        perror("listen");
        exit(3);
    }

    fdmax = sockfd;
    FD_ZERO(&master);
    FD_ZERO(&readfds);
    FD_SET(sockfd, &master);
    FD_SET(0, &readfds);

    printf("server: waiting for connections...\n");

    for (;;) {
        readfds = master;

        if ((r = select(fdmax + 1, &readfds, NULL, NULL, NULL)) == -1) {
            perror("select");
            exit(4);
        }

        for (i = 0; i <= fdmax; ++i) {
            if (FD_ISSET(i, &readfds)) {
                if (i == sockfd) {
                    sin_size = sizeof(their_addr);

                    if ((new_fd = accept(sockfd, (struct sockaddr *) &their_addr, &sin_size)) == -1) {
                        perror("accept");
                        exit(5);
                    }

                    inet_ntop(
                        their_addr.ss_family,
                        &(((struct sockaddr_in *) &their_addr)->sin_addr),
                        s,
                        sizeof(s)
                    );

                    FD_SET(new_fd, &master);
                    fdmax = new_fd;

                    printf("server: got connection from %s %d\n", s, new_fd);
                } else {
                    int nread;

                    if ((nread = recv(i, buf, sizeof(buf), 0)) <= 0) {
                        fprintf(stderr, "Client hung up, closing socket.");
                        close(i);
                        FD_CLR(i, &master);
                    } else {
                        write(1, buf, nread);
                    }
                }
            }
        }
    }

    return 0;
}

