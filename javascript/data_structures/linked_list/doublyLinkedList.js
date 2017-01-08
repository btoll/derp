/* eslint-disable no-console */

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

    insertFirst(data) {
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

    insertLast(data) {
        if (!list._tail) {
            list.insertFirst(data);
        } else {
            const newTail = list.create(data);
            const oldTail = list._tail;

            newTail.prev = oldTail;
            oldTail.next = newTail;
            list._tail = newTail;
        }
    }
};


list.insertFirst(7);
list.insertFirst(5);
list.insertLast(42);
list.delete(list.find(7));
list.deleteHead();
list.insertLast(666);

