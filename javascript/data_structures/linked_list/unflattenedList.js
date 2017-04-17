const list = {
    _head: null,
    _tail: null,

    create(data) {
        return {
            next: null,
            prev: null,
            child: null,
            data: data
        };
    },

    getHead() {
        return this._head;
    },

    getTail() {
        return this._tail;
    },

    insertFirst(data) {
        const newHead = this.create(data);

        if (!this._head) {
            this._head = this._tail = newHead;
        } else {
            const oldHead = this._head;

            newHead.next = oldHead;
            oldHead.prev = newHead;
            this._head = newHead;
        }

        return newHead;
    },

    insertLast(data) {
        if (!this._tail) {
            this.insertFirst(data);
        } else {
            const newTail = this.create(data);
            const oldTail = this._tail;

            newTail.prev = oldTail;
            oldTail.next = newTail;
            this._tail = newTail;
        }
    }
};

const flattenList = list => {
    let item = list.getHead();

    while (item) {
        if (item.child) {
            append(item.child, list);
        }

        item = item.next;
    }
};

// Make the head of the child list the new tail.
const append = (item, list) => {
    const oldTail = list.getTail();

    oldTail.next = item;
    item.prev = oldTail;

    // We just want to advance to the last node here.
    while (item.next) {
        item = item.next;
    }

    list._tail = item;
};

// Make lists.
const l1 = Object.create(list);
l1.insertFirst(5);
l1.insertLast(33);
l1.insertLast(17);
l1.insertLast(2);
l1.insertLast(1);

const l2 = Object.create(list);
l2.insertFirst(6);
l2.insertLast(25);
l2.insertLast(6);

const l3 = Object.create(list);
l3.insertFirst(2);
l3.insertLast(7);

const l4 = Object.create(list);
l4.insertFirst(8);

const l5 = Object.create(list);
l5.insertFirst(9);

const l6 = Object.create(list);
l6.insertFirst(12);
l6.insertLast(5);

const l7 = Object.create(list);
l7.insertFirst(7);

const l8 = Object.create(list);
l8.insertFirst(21);
l8.insertLast(3);

// Set child nodes.
l1.getHead().child = l2.getHead();
l1.getTail().prev.child = l3.getHead();

l2.getHead().next.child = l4.getHead();
l2.getTail().child = l5.getHead();

l3.getHead().child = l6.getHead();
l5.getHead().child = l7.getHead();
l6.getHead().child = l8.getHead();

flattenList(l1);

//let item = l1.getTail();
//
//while (item) {
//    if (item.child) {
//        debugger;
//        item.child.prev = null;
//    }
//
//    item = item.prev;
//}

const a = [];
let item = l1.getHead();

while (item) {
    if (item.child) {
        a.push(item.child);
    }

    item = item.next;
}

a.reverse().forEach((child, index) => {
    if (index === (a.length - 1)) {
        l1._tail = child.prev;
    }

    // Decouple the links.
    child.prev.next = null;
    child.prev = null;
});

