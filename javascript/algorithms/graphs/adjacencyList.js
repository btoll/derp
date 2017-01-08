const edgeList = [
    [0, 2], [1, 3], [2, 3], [2, 4], [3, 5], [4, 5]
];

// TODO: This doesn't handle sparse arrays or unordered edge lists correctly!!
//
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

// Note this is a directed graph (edges are not symmetric).
//
// [ 0 -> [ 2 ],
//   1 -> [ 3 ],
//   2 -> [ 3, 4 ],
//   3 -> [ 5 ],
//   4 -> [ 5 ] ]
//
const makeAdjacencyList = array => {
    const list = [];
    const [rows] = getMatrixShape(array);

    // Create an array for each row.
    for (let i = rows[0], len = rows[1]; i <= len; i++) {
        list.push([]);
    }

    // Push the "col" vertex into the appropriate "row" list.
    array.forEach(edge =>
        list[edge[0]]
        .push(edge[1])
    );

    return list;
};

const sortFn = (a, b) =>
    a > b

const list = makeAdjacencyList(edgeList);

console.log(list);

console.assert(list[2][0] === 3);
console.assert(list[2][1] === 4);
console.assert(list[4][0] === 5);
console.assert(list[0][1] === undefined);

