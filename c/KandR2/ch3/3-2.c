#include <stdio.h>
#include <string.h>

void escape(char *s, char *t) {
    int i = 0, j = 0;

    while (t[i]) {
        switch (t[i]) {
            case '\b':
                s[j++] = '\\';
                s[j] = 'b';
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
                break;
            default:
                s[j] = t[i];
                break;
        }

        t++;
        j++;
    }

    s[j] = '\0';
}

void unescape(char *s, char *t) {
    int i = 0, j = 0;

    while (t[i]) {
        switch (t[i]) {
            case '\\':
                switch (t[++i]) {
                    case 'b':
                        s[j] = '\b';
                    case 'n':
                        s[j] = '\n';
                    case 't':
                        s[j] = '\t';
                        break;
                }
            default:
                s[j] = t[i];
                break;
        }

        t++;
        j++;
    }

    s[j] = '\0';
}

int main(int argc, char **argv) {
//     char *str = "foo \n bar\t    \n ";
    char *str = "\aHello,\n\tWorld! Mistakee\b was \"Extra 'e'\"!\n";
    char *buff;

    escape(buff, str);
    printf("%s\n", buff);

    printf("\n\n\n");

    unescape(buff, str);
    printf("%s\n", buff);

    return 0;
}

