const edgeList = [ [0, 2], [1, 3], [2, 3], [2, 4], [3, 5], [4, 5] ];

// First, make the matrix, with vertices of zero.
// Second, go through the array and plug in the edge values.
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

    array.forEach(() => {
        const r = [];

        for (let i = 0, len = array.length; i < len; i++) {
            r[i] = 0;
        }

        matrix.push(r);
    });

    array.forEach(([x, y]) => {
        matrix[x][y] = 1;
    });

    return matrix;
};

const makeAdjacencyList = array => {
};

console.log(makeAdjacencyMatrix(edgeList));
// console.log(makeAdjacencyList(edgeList));

