#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// cat pipes.c | grep fork

int main(int argc, char **argv) {
    int fd[2];

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    if (!fork()) {
        close(fd[0]);

        if (dup2(fd[1], 1) == -1) {
            perror("dup2");
            _exit(1);
        }

        if (execlp("cat", "cat", "pipes.c", NULL) == -1) {
            perror("execlp");
            _exit(1);
        }

        _exit(0);
    } else {
        wait(NULL);
        close(fd[1]);

        if (dup2(fd[0], 0) == -1) {
            perror("dup2");
            exit(1);
        }

        if (execlp("grep", "grep", "fork", NULL) == -1) {
            perror("execlp");
            exit(1);
        }
    }

    return 0;
}

