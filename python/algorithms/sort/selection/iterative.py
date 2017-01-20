import sys

def swap(toSort, i, j):
    tmp = toSort[i]
    toSort[i] = toSort[j]
    toSort[j] = tmp

def selectionSort(toSort):
    length = len(toSort)

    for i in range(0, length):
        for j in range(i + 1, length):
            if toSort[j] < toSort[i]:
                swap(toSort, i, j)

    return toSort

def main(argv):
    toSort = [188, 9, 7, 1, 5, 7777, 4, 3, 1, -99]
    print('initial sort order', toSort)
    print('            sorted', selectionSort(toSort))

if __name__ == '__main__':
    main(sys.argv[1:])

