import sys

def swap(toSort, i, j):
    tmp = toSort[i]
    toSort[i] = toSort[j]
    toSort[j] = tmp

def findMinimumIndex(toSort, i):
    min = i

    for j in range(i, len(toSort)):
        if toSort[j] < toSort[i]:
            min = j
            i = j

    return min

def selectionSort(toSort):
    length = len(toSort)

    # Decrement length by one to prevent an `IndexError: list index out of range error`
    # since we're always searching for the current index + 1.
    for i in range(0, length - 1):
        swap(toSort, i, findMinimumIndex(toSort, i + 1))

    return toSort

def main(argv):
    toSort = [188, 9, 7, 1, 5, 7777, 4, 3, 1, -99]
    print('initial sort order', toSort)
    print('            sorted', selectionSort(toSort))

if __name__ == '__main__':
    main(sys.argv[1:])

