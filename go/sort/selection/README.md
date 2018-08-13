# Selection Sort

### Asymptotic Complexity

In all cases:

> Θ(n<sup>2</sup>)

Outer loop:

> Θ(n)

Inner loop:

> Θ(n<sup>2</sup>)


Swap call

> Θ(n)

---

Q. Why is the inner loop so time consuming?

A. Because it's an arithmetic series, so every iteration will be `n - index`:

```
(n - 1) + (n - 2) + (n - 3) + (n - 4) + ... + (n) = (n + 1)(n / 2)
or
1 + 2 + 3 + 4 + (n - 1) = (n + 1)(n / 2)
```

