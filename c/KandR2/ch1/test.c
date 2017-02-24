#include <stdio.h>
#include <string.h>

int main(void) {
    char msg[] = "Hello";

    printf("%s\n", msg);
    printf("%d\n", strlen(msg));

    printf("%s\n", msg);
    printf("%c\n", msg[1]);

    *msg = '\0';
    printf("%d\n", strlen(msg));
    printf("%c\n", msg[1]);

    return 0;
}

