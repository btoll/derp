# Selection Sort

### Asymptotic Complexity

    Θ(n²)

### Description of Solution

The solution swaps two array elements repeatedly until the array is sorted.

The solution will iterate over the unsorted portion of the array looking for the smallest number in that subarray, and when found the index of that number is swapped with the starting index of that unsorted subarray. The index of the smallest number in the subarray should be exchanged for another if one is found while iterating over the remainder of the subarray, and that smallest number is swapped with the starting index of the unsorted subarray when the end of the unsorted portion has been reached.

So, the array to be sorted is divided into two subarrays, conceptually.  The left subarray is sorted and the right subarray is unsorted.

As an example, assume that the array to be sorted has just had the smallest number in the array swapped into the first position.  At this point, the sorted subarray has a "length" of one.  The starting index is then incremented from `0` to `1`, and the array is again iterated to find the smallest number, at which point the next swap occurs.  The sorted subarray now has a "length" of two, and the starting index is now incremented from `1` to `2`. This process repeats until the array is sorted.

Note that every element in the array must be checked, so this algorithm doesn't have a best case scenario such as θ(n) like its cousin the [insertion sort].

### Helpful Tips

- It helps to think of the problem as a (growing) sorted subarray to the left of the unexamined portion of the unsorted array.

- When possible, it's helpful to break the problem down into substeps. For example, since swapping two indices is integral to the algorithm, coding up a helper function that does the actual swap is an important step in solving the problem as a whole.

### Steps

1. Find the smallest number and swap it with the first number.
2. Find the second smallest number and swap it with the second number.
3. Find the third smallest number and swap it with the third number.
4. Repeat until the array is sorted.

[insertion sort]: /javascript/algorithms/sort/insertion/

