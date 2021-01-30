nums = [-99, -1, 1, 3, 4, 5, 7, 9, 188, 7777]

def binary_search(p, r, n):
    if p > r:
        return -1

    q = (p + r) >> 1

    if nums[q] == n:
        return q

    if nums[q] < n:
        return binary_search(q + 1, r, n)
    else:
        return binary_search(p, q - 1, n)

def main():
#    for i in range(len(nums)):
#        print(binary_search(0, len(nums), nums[i]))

    return binary_search(0, len(nums), 1)

if __name__ == "__main__":
    print(main())

