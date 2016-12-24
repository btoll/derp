# Binary Search

### Asymptotic Complexity

    O(lg n)

### Steps

1. Let `min` = 0 and `max` = n - 1.
2. Check if the `max` number is greater than the `min` number. If so, the target number isn't in the array, return -1.
3. Calculate the `guess` as the average of `max` and `min`, flooring the result.
4. If `array[guess]` = target, then you've found it!.
5. If `array[guess]` is lower than the value of the target number, then shift the pool of remaining guess one slot to the right of `min`.

    `min = guess + 1`

6. If the `array[guess]` is greater than the value of the target number, then shift the pool of remaining guess one slot to the left of `max`.

    `max = guess - 1`

7. Repeat.

