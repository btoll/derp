from pprint import pprint as pp


ROWS = 10
COLS = 10

xNeighbors = ( -1, -1, -1, 0, 0, 1, 1, 1 )
yNeighbors = ( -1, 0, 1, -1, 1, -1, 0, 1 )


def makeMatrix():
    return [
        [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
        [ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 ],
        [ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 ],
        [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
        [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
        [ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 ],
        [ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 ],
        [ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 ],
        [ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 ],
        [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
    ]


before = makeMatrix()
after = makeMatrix()


def countAlive(i, j):
    count = 0

    for k in range(8):
        newX = i + xNeighbors[k]
        newY = j + yNeighbors[k]

        if newX > -1 and newY > -1 and newX < ROWS and newY < COLS:
            count += before[newX][newY]

    cell = before[i][j]

    if cell and count < 2:
        after[i][j] = 0
    elif cell and count > 3:
        after[i][j] = 0
    elif cell == 0 and count == 3:
        after[i][j] = 1
    else:
        after[i][j] = cell


def main():
    print('before')
    pp(before)

    for i in range(ROWS):
        for j in range(COLS):
            countAlive(i, j)

    print('\nafter')
    pp(after)


if __name__ == "__main__":
    main()

