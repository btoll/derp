/* eslint-disable no-console, no-constant-condition */

const isCyclic = list => {
    let slow = list._head;
    let fast = list._head.next;

    while (true) {
        if (!fast || !fast.next) {
            return false;
        }

        if (slow !== fast) {
            slow = slow.next;
            fast = fast.next.next;
        } else {
            return true;
        }
    }
};

const list = {
    _head: null,
    _tail: null,

    create(data) {
        return {
            next: null,
            prev: null,
            data: data
        };
    },

    add(data) {
        const newHead = list.create(data);

        if (!list._head) {
            list._head = list._tail = newHead;
        } else {
            const oldHead = list._head;

            newHead.next = oldHead;
            oldHead.prev = newHead;
            list._head = newHead;
        }

        return newHead;
    },

    append(data) {
        let newTail;

        if (!list._tail) {
            newTail = list.add(data);
        } else {
            const newTail = list.create(data);
            const oldTail = list._tail;

            newTail.prev = oldTail;
            oldTail.next = newTail;
            list._tail = newTail;
        }

        return newTail;
    },

    delete(toRemove) {
        let head = list._head;

        if (head === toRemove) {
            list._head = toRemove.next;
            toRemove = list._head.prev = null;
        } else {
            while (head) {
                if (head.next === toRemove) {
                    if (list._tail === toRemove) {
                        list._tail = toRemove.prev;
                        list._tail.next = null;
                    } else {
                        const newNextLink = toRemove.next;
                        head.next = newNextLink;
                        newNextLink.prev = head;
                    }

                    toRemove = null;
                    break;
                }

                head = head.next;
            }
        }
    },

    deleteHead() {
        if (list._head) {
            const next = list._head.next;

            delete list._head;
            list._head = next;
            list._head.prev = null;
        }
    },

    deleteList() {
        while (list._head) {
            const next = list._head.next;
            delete list._head;
            list._head = next;
        }
    },

    find(data) {
        let item = list._head;

        while (item !== null && item.data !== data) {
            item = item.next;
        }

        return item;
    },

    insertAfter(prev, data) {
        const newNode = list.create(data);
        const after = prev.next;

        newNode.prev = prev;
        newNode.next = after;

        prev.next = newNode;
        after.prev = newNode;

        // TODO:
        // if (list._tail);

        return newNode;
    },

    print() {
        let head = list._head;

        while (head) {
            console.log(head.data);
            head = head.next;
        }
    }
};

// 17 -> 3 -> 100 -> 42 -> 5 -> 1972

list.add(1972);
list.add(5);
list.add(42);
const n100 = list.add(100);
list.add(3);
list.add(17);
list.append(666);

list.insertAfter(n100, 200);
// list.print();

// 17 -> 3 -> 100 -> 200 -> 42 -> 5 -> 1972 -> 666

console.log(isCyclic(list));
list._tail.next = n100;
console.log(isCyclic(list));

