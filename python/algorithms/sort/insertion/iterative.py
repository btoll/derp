import sys

def insert(toSort, dropIndex):
    previous = dropIndex - 1
    key = toSort[dropIndex]

    while previous > -1 and key < toSort[previous]:
        # Shift right.
        toSort[dropIndex] = toSort[previous]

        dropIndex -= 1
        previous -= 1

    toSort[dropIndex] = key

def insertionSort(toSort):
    for i in range(1, len(toSort)):
        insert(toSort, i)

    return toSort

def main(argv):
    toSort = [188, 9, 7, 1, 5, 7777, 4, 3, 1, -99]
    print('initial sort order', toSort)
    print('            sorted', insertionSort(toSort))

if __name__ == '__main__':
    main(sys.argv[1:])

