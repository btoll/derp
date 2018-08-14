# Insertion Sort

### Asymptotic Complexity

Worst case:

- A reverse-sorted array.
- A randomly sorted array.

> Θ(n<sup>2</sup>)

Best case:

- A sorted array.
- An "almost" sorted array.

> Θ(n)

---

For the worst case scenario, every element in the "subarray" to the left of the element to insert is greater than that element.  In these cases, the sort is also an arithmetic series (like the [selection sort]), except in this case it goes up to `n - 1` rather than `n`.  This is because we start the loop at index 1, since an array of one integer is considered sorted.

[selection sort]: /go/sort/selection/README.md

