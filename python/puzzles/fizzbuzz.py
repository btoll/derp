import sys

def fizzbuzz():
    for i in range(0x1, 0x65):
        fizz = 0x0
        buzz = 0x0

        if i % 0x3 == 0x0:
            fizz = 0x3
            print('fizz', i)

        if i % 0x5 == 0x0:
            buzz = 0x5
            print('buzz', i)

        if (fizz & buzz) == 0x1:
            print('fizzbuzz', i)

def main(argv):
    fizzbuzz()

if __name__ == '__main__':
    main(sys.argv[1:])

