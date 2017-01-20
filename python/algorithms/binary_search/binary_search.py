import sys

array = [-99, -1, 1, 3, 4, 5, 7, 9, 188, 7777]

def binary_search(min, max, target):
    if min > max:
        return False

    guess = int((max + min) / 2)

    if array[guess] == target:
        return target

    if array[guess] < target:
        return binary_search(guess + 1, max, target)
    else:
        return binary_search(min, guess - 1, target)

def main(argv):
    print(binary_search(0, len(array) - 1, 1))

if __name__ == '__main__':
    main(sys.argv[1:])

