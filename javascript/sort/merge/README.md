# Merge Sort

### Asymptotic Complexity

    Θ(n lg n)

### Description of Solution

The merge sort employs a divide-and-conquer algorithmic paradigm, which one can think of as encompassing the following steps:

1. Divide
    - will take constant time, Θ(1)
    - very little time is spent in this step

2. Conquer
    - will take linearithmic time, Θ(n lg n)

3. Combine
    - will take linear time, Θ(n)
    - the meat of the algorithm occurs in this step

It will first halve the array into subarrays (the Divide step) and then recursively sort the subarrays (the Conquer step) until it reaches the base case (when the subarray consists of zero or one elements - in which case we consider it to be sorted).

The algorithm will then merge these sorted subarrays in the Combine step.

One of the drawbacks of merge sort is that it does not work in-place, due to the fact that the combine step is not working with a constant size of arrays. However, this may not be an issue, depending on the amount of available memory.

### Steps

1. Divide (halve) the array into two subarrays.
2. Keep dividing the subarrays until the base case is reached.
3. Merge the sorted subarrays back into one array.

