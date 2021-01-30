def merge(array, p, q, r):
    lowHalf = array[p:q + 1]
    highHalf = array[q + 1:r + 1]
    i = 0
    j = 0
    k = p

    while i < len(lowHalf) and j < len(highHalf):
        if lowHalf[i] < highHalf[j]:
            array[k] = lowHalf[i]
            i += 1
        else:
            array[k] = highHalf[j]
            j += 1

        k += 1

    while i < len(lowHalf):
        array[k] = lowHalf[i];
        i += 1;
        k += 1;

    while j < len(highHalf):
        array[k] = highHalf[j];
        j += 1;
        k += 1;

def mergeSort(array, p, r):
    if p >= r:
        return array

    # Divide and conquer.
    q = int((p + r) / 2)

    mergeSort(array, p, q);
    mergeSort(array, q + 1, r);
    merge(array, p, q, r);
    return array


def main():
    array = [188, 9, 7, 1, 5, 7777, 4, 3, 1, -99]
    print('initial sort order', array)
    print('            sorted', mergeSort(array, 0, len(array) - 1))

if __name__ == '__main__':
    main()

