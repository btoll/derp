#include <stdio.h>
#include <string.h>

// This is a more efficient solution.  It changes the string in-place.
//
// TODO: To create the segfault:
//      1. uncomment line 21
//      2. comment line 23
//
//      For a bonus, watch it disappear when uncommenting line 35!
void reverse(char s[], int m, int n) {
    int c;

    for (; m < n; m++, n--) {
        c = s[m];
        s[m] = s[n];
        s[n] = c;
    }
}

void reverseWords(char s[]) {
    int curPos = 0, wordStart = 0;
    int len = strlen(s);

    while (s[curPos] != '\0') {
//         for (; s[curPos] != ' ' && s[curPos] != '\0'; curPos++)
        for (; s[curPos] != ' ' && curPos < len; curPos++)
            ;

        reverse(s, wordStart, curPos - 1);
        wordStart = ++curPos;
    }
}

int main(void) {
    char s[] = "in search of algorithmic elegance";
//     int n = 0;

    reverse(s, 0, strlen(s) - 1);
    reverseWords(s);

    printf("%s\n", s);

    return 0;
}

