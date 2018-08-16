# Merge Sort

### Asymptotic Complexity

Total running time:

> Θ(n log<sub>2</sub> n))

Divide step:

> Θ(1)

When merging elements in the combine step:

> Θ(n)

Divide and combine steps together:

> Θ(n)

---

The divide step divides `n` in half for every call, and so the conquer step is always working on `n/2` elements.  With the base call (`p < r`), this will eventually get to only a one-element slice, at which point the stack will unwind.

Here's an image, courtesy of [Khan Academy]:

![ScreenShot](https://raw.github.com/btoll/i/master/derp/merge_sort_analysis.png)

The number of subproblems doubles at each level, but this ends up being a wash as the merge time is halved at each level.

The running time for the merge step is then:

l = log<sub>2</sub>n + 1, where `l` represents the number of levels in the recursive tree.

The total time for `mergeSort` (see the source code) then is cn(log<sub>2</sub>n + 1).  Of course, when analysing the running time using [Big O notation], we discard the lower-order term (+1) and the constant (cn) to give us:

> Θ(n log<sub>2</sub> n))

For a 16-element slice:

log<sub>2</sub>16 + 1 = 5

---

Note that Tthis is not considered an in-place algorithm because the merge (combine) step copies more than `n` elements (into the `lowHalf` and `highHalf` slices).

[Khan Academy]: https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/analysis-of-merge-sort
[Big O notation]: https://en.wikipedia.org/wiki/Big_O_notation

