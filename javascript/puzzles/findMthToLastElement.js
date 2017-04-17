const list = require('../include/linkedList');

const findMthToLastElement = n => {
    let curPos = list._head;
    let mth = list._head;

    for (let i = 0; i < n; i++) {
        if (!curPos) {
            throw new Error('Range too great');
        }

        curPos = curPos.next;
    }

    while (curPos.next) {
        curPos = curPos.next;
        mth = mth.next;
    }

    return mth;
};

for (let i = 0; i < 20; i++) {
    list.appendNode(i);
}

console.log(findMthToLastElement(11).data);

