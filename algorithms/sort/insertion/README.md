# Insertion Sort

### Asymptotic Complexity

    θ(n²)

### Description of Solution

The solution examines all of the elements to the left of a given position, or key, and will then slide all those array elements to the right that are greater than the key. The key is then dropped into the first slot where it is greater than or equal to the element to its immediate left. Repeating this process will sort the array.

Note that this algorithm has a best case scenario of θ(n) and could perform better than the [selection sort]. The reason for this is simple: if the subarray is already sorted, then the key doesn't have to move (and no elements to its left have to be moved to the right) if it's greater than or equal to the element immediately to its left.

Inversely, the worst case scenario of the array (and thus the subarray) has been reversed sorted, so then every element must be shifted to the right and the key dropped into the first position.

### Helpful Tips

- It helps to think of the problem as a (growing) sorted subarray to the left of the unexamined portion of the unsorted array.

- When possible, it's helpful to break the problem down into substeps. For example, since swapping two indices is integral to the algorithm, coding up a helper function that does the actual swap is an important step in solving the problem as a whole.

### Steps

[selection sort]:/sort/selection

