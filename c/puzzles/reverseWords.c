#include <stdio.h>
#include <string.h>

// This version uses dynamic memory allocation and a temporary buffer.
//
char *reverseWords(char *s, char *buf, int size) {
    int curPos, wordBegin, wordEnd, writePos = 0;

    for (curPos = size - 1; curPos >= 0; curPos--) {
        if (s[curPos] == ' ') {
            buf[writePos++] = s[curPos];
        } else {
            for (wordEnd = curPos; s[curPos] != ' ' && curPos >= 0; curPos--)
                ;

            // Add one b/c currently both variables are one char before the word.
            wordBegin = ++curPos;

            while (wordBegin <= wordEnd)
                buf[writePos++] = s[wordBegin++];
        }
    }

    buf[size] = '\0';
}

int main(int argc, char **argv) {
//     char *s = "Do or do not, there is no try.";
    char *s = "in search of algorithmic elegance";
    int size = strlen(s);
    char buf[size];

    reverseWords(s, buf, size);
    printf("'");
    printf("%s'\n", buf);

    return 0;
}

