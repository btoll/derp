#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int fd[2];
    pid_t p;
    FILE *stream;
    char buf[1024];

    pipe(fd);

    if ((p = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    if (p == 0) {                   /* child */
        // close write end of pipe
        close(fd[1]);

        // convert low-level fd to a high-level readable stream object
        stream = fdopen(fd[0], "r");

        // read from stream and print to stdout
        fgets(buf, sizeof(buf), stream);
        fputs(buf, stdout);

        close(fd[0]);
    } else {                        /* parent */
        // close read end of pipe
        close(fd[0]);

        // convert low-level fd to a high-level writeable stream object
        stream = fdopen(fd[1], "w");

        // write to stream
        fprintf(stream, "hello, world!\n");

        // if we don't flush the string may not be sent through the pipe immediately and the fd will be closed before it does
        fflush(stream);
        close(fd[1]);
    }

    return 0;
}

