const node = (v, l = null, r = null) => {
    return {
        value: v,
        left: l,
        right: r
    };
};

//
//              __ 43 __
//             /         \
//         19              35
//       /    \          /    \
//     12      4       2       20
//    /
//   6
//

const queue = [43, 19, 35, 12, 4, 2, 20, 6];

const createTreeFromQueue = queue => {
    const root = node(queue[0]);
    const pqueue = [root];

    for (let n = 1, len = queue.length; n < len; n++) {
        const newNode = node(queue[n]);
        const parent = (n - 1) / 2 >> 0;
        const direction = n % 2 !== 0 ?
            'left' :
            'right';

        // Bind the new child node to its parent using the formula `Math.floor((n - 1) / 2)`.
        pqueue[parent][direction] = newNode;
        pqueue.push(newNode);
    }

    return root;
};

const initQueue = () => {
    const queue = [];

    return {
        dequeue: () => queue.shift(),
        enqueue: item => queue.push(item),
        isEmpty: () => !queue.length
    };
};

const createQueueFromTree = tree => {
    // Left node: 2n + 1
    // Right node: 2n + 2

    const res = [];
    const q = initQueue();

    q.enqueue(tree);

    while (!q.isEmpty()) {
        const node = q.dequeue();

        res.push(node.value);

        if (node.left) {
            q.enqueue(node.left);
        }

        if (node.right) {
            q.enqueue(node.right);
        }
    }

    return res;
};

console.log('createTree', createQueueFromTree(
    createTreeFromQueue(queue)
));

