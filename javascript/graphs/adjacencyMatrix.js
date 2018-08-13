const edgeList = [
    [0, 2], [1, 3], [2, 3], [2, 4], [3, 5], [4, 5]
];

// 1. Reduce the edgeList to:
//      array[
//          [ all row values ],
//          [ all col values ]
//      ]
//
// 2. Sort.
// 3. Return the min and max values.
const getMatrixShape = array => {
    const [rows, cols] = array.reduce((acc, curr) => (
        acc[0].push(curr[0]),
        acc[1].push(curr[1]),
        acc
    ), [[], []]);

    rows.sort(sortFn);
    cols.sort(sortFn);

    return [
        [
            rows[0],
            rows[rows.length - 1]
        ],
        [
            cols[0],
            cols[cols.length - 1]
        ]
    ];
};

// First, make the matrix, with vertices of zero.
// Second, go through the array and plugin the edge values.
//
// Note this is a directed graph (edges are not symmetric).
//
// [ [ 0, 0, 1, 0, 0, 0 ],
//   [ 0, 0, 0, 1, 0, 0 ],
//   [ 0, 0, 0, 1, 1, 0 ],
//   [ 0, 0, 0, 0, 0, 1 ],
//   [ 0, 0, 0, 0, 0, 1 ],
//   [ 0, 0, 0, 0, 0, 0 ] ]
//
const makeAdjacencyMatrix = array => {
    const matrix = [];
    const [rows, cols] = getMatrixShape(array);

    for (let i = rows[0], len = rows[1]; i <= len; i++) {
        const r = [];

        for (let j = 0, jlen = cols[1]; j <= jlen; j++) {
            r[j] = 0;
        }

        matrix.push(r);
    }

    array.forEach(([x, y]) => {
        matrix[x][y] = 1;
    });

    return matrix;
};

const sortFn = (a, b) =>
    a > b

const matrix = makeAdjacencyMatrix(edgeList);

console.log(matrix);

console.assert(matrix[0][2] === 1);
console.assert(matrix[2][3] === 1);
console.assert(matrix[2][4] === 1);
console.assert(matrix[4][3] === 0);

