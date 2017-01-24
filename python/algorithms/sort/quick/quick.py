import sys

def swap(array, i, j):
    tmp = array[i]
    array[i] = array[j]
    array[j] = tmp

def partition(array, p, r):
    j = p
    q = p
    pivot = array[r]

    while j < r:
        if array[j] <= pivot:
            swap(array, q, j)
            q += 1

        j += 1

    swap(array, q, r)

    return q

def quickSort(array, p, r):
    if (p >= r):
        return array

    pivot = partition(array, p, r)

    quickSort(array, p, pivot - 1)
    quickSort(array, pivot + 1, r)

    return array

def main(argv):
    array = [2, 188, 9, 7, 1, 5, 7777, 4, 3, 1, -99, 10, 13]
    print('initial sort order', array)
    print('            sorted', quickSort(array, 0, len(array) - 1))

if __name__ == '__main__':
    main(sys.argv[1:])

