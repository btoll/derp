def fib(n):
    a = 1
    b = 0

    for i in range(n):
        a, b = b, a + b
        print(a)


if __name__ == "__main__":
    fib(10)

