nums = [ 188, 9, 7, 1, 5, 7777, 4, 3, 1, -99 ]

def merge(p, q, r):
    low = nums[p:q + 1]
    high = nums[q + 1:r + 1]
    i = 0
    j = 0
    k = p

    while i < len(low) and j < len(high):
        if low[i] < high[j]:
            nums[k] = low[i]
            i += 1
        else:
            nums[k] = high[j]
            j += 1

        k += 1

    while i < len(low):
        nums[k] = low[i]
        i += 1
        k += 1

    while j < len(high):
        nums[k] = high[j]
        j += 1
        k += 1


def merge_sort(p, r):
    if p >= r:
        return nums

    q = (p + r) >> 1;

    merge_sort(p, q)
    merge_sort(q + 1, r)
    merge(p, q, r)


def main():
    merge_sort(0, len(nums) - 1)


if __name__ == '__main__':
    print('before', nums)
    main()
    print('after', nums)

