// NOTE: This code is from an exercise taken from Khan Academy and is not mine!!!
// https://www.khanacademy.org/computing/computer-science/algorithms/breadth-first-search/p/challenge-implement-breadth-first-search
//
/* A Queue object for queue-like functionality over JavaScript arrays. */
const Queue = function() {
    this.items = [];
};

Queue.prototype.enqueue = function(obj) {
    this.items.push(obj);
};

Queue.prototype.dequeue = function() {
    return this.items.shift();
};

Queue.prototype.isEmpty = function() {
    return this.items.length === 0;
};

/*
 * Performs a breadth-first search on a graph
 * @param {array} graph - Graph, represented as adjacency lists.
 * @param {number} source - The index of the source vertex.
 * @returns {array} Array of objects describing each vertex, like
 *     [{distance: _, predecessor: _ }]
 */
const doBFS = function(graph, source) {
    const bfsInfo = [];

    for (let i = 0; i < graph.length; i++) {
	    bfsInfo[i] = {
	        distance: null,
	        predecessor: null };
    }

    bfsInfo[source].distance = 0;

    const queue = new Queue();
    queue.enqueue(source);

    // Traverse the graph

    // As long as the queue is not empty:
    //  Repeatedly dequeue a vertex u from the queue.
    //
    //  For each neighbor v of u that has not been visited:
    //     Set distance to 1 greater than u's distance
    //     Set predecessor to u
    //     Enqueue v
    //
    //  Hint:
    //  use graph to get the neighbors,
    //  use bfsInfo for distances and predecessors
    while (!queue.isEmpty()) {
        const predecessor = queue.dequeue();
        const neighbors = graph[predecessor];

        for (let i = 0, len = neighbors.length; i < len; i++) {
            const neighbor = neighbors[i];

            if (bfsInfo[neighbor].distance === null) {
                queue.enqueue(neighbors[i]);

                bfsInfo[neighbor].distance = bfsInfo[predecessor].distance + 1;
                bfsInfo[neighbor].predecessor = predecessor;
            }
        }
    }

    return bfsInfo;
};


const adjList = [
    [1],
    [0, 4, 5],
    [3, 4, 5],
    [2, 6],
    [1, 2],
    [1, 2, 6],
    [3, 5],
    []
    ];

const bfsInfo = doBFS(adjList, 3);

for (let i = 0; i < adjList.length; i++) {
    console.log('vertex ' + i + ': distance = ' + bfsInfo[i].distance + ', predecessor = ' + bfsInfo[i].predecessor);
}

