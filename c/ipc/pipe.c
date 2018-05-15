#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Implement `ls | wc -l`

int main(void) {
    int pfds[2];

    if (pipe(pfds) == -1) {
        perror("pipe");
        exit(1);
    }

    if (!fork()) {
        close(pfds[0]);
        dup2(pfds[1], 1);
        execlp("ls", "ls", NULL);
    } else {
        wait(NULL);
        close(pfds[1]);
        dup2(pfds[0], 0);
        execlp("wc", "wc", "-l", NULL);
    }

    return 0;
}

