#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

// void main() {
//     int i;
//     char char_str[5];
//     strcpy(char_str, "abcde");

//     unsigned int hacky_nonpointer;
//     hacky_nonpointer = (unsigned int) char_str;

//     for (i = 0; i < 5; i++) {
//         printf("'%c'\n", *((char *) hacky_nonpointer));
//         hacky_nonpointer = hacky_nonpointer + sizeof(char);
//     }
// }

void main(void) {
    printf("char\n");
    printf("\tSizeof char is %d\n", sizeof(char));
    printf("\tSizeof signed char is %d\n", sizeof(signed char));
    printf("\tSizeof unsigned char is %d\n", sizeof(unsigned char));

    printf("\nint\n");
    printf("\tSizeof signed short int is %d\n", sizeof(signed short int));
    printf("\tSizeof unsigned short int is %d\n", sizeof(unsigned short int));
    printf("\n");

    printf("\tSizeof int is %d\n", sizeof(int));
    printf("\tSizeof signed int is %d\n", sizeof(signed int));
    printf("\tSizeof unsigned int is %d\n", sizeof(unsigned int));
    printf("\n");

    printf("\tSizeof signed long int is %d\n", sizeof(signed long int));
    printf("\tSizeof unsigned long int is %d\n", sizeof(unsigned long int));
}

