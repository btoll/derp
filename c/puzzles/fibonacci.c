#include <stdio.h>

int fibonacci(int n) {
    if (n < 2) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char **argv) {
    printf("Fibonacci number is %d\n", fibonacci(20));
    return 0;
}

