# Quick Sort

### Asymptotic Complexity

    Θ(n lg n)

### Description of Solution

Quick sort employs a divide-and-conquer algorithmic paradigm, which one can think of as encompassing as the following steps:

1. Divide
    - will take constant time, Θ(1)

2. Conquer
    - will take linearithmic time, Θ(n lg n)

3. Combine
    - will take linear time, Θ(n)

It will first recursively break the problem (the array to sort) into subproblems by halving the array into subarrays until it reaches the base case, which is when the subarray consists of zero or one elements (in which case we consider it to be sorted).

The algorithm will then merge these sorted subarrays in another step.

Unlike its cousin the [merge sort], quicksort sorts in-place. This may be a significant consideration if space is a constraining factor.

### Steps

[merge sort]: /javascript/algorithms/sort/merge/

