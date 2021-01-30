from math import sqrt


def is_prime(n):
    if n < 2:
        return False

    for k in range(2, int(sqrt(n)) + 1):
        if n % k == 0:
            return False

    return True


if __name__ == "__main__":
    is_prime()

#[n for n in range(100) if is_prime(n)]
#{n*n: (1, n, n*n) for n in range(101) if is_prime(n)}

