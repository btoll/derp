/* eslint-disable no-console */

const list = {
    _head: null,

    create(data) {
        return {
            next: null,
            data: data
        };
    },

    delete(toRemove) {
        let item = list._head;

        if (item === toRemove) {
            list._head = toRemove.next;
            toRemove = null;
        } else {
            while (item) {
                if (item.next === toRemove) {
                    item.next = toRemove.next;
                    toRemove = null;
                    break;
                }

                item = item.next;
            }
        }
    },

    deleteHead() {
        if (list._head) {
            const next = list._head.next;
            delete list._head;
            list._head = next;
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

    /*
    findNthToLast(n) {
        let item = list._head;
        let nthItem = list._head;
        let i = 0;

        while (item) {
            item = item.next;

            if (i++ >= n) {
                nthItem = nthItem.next;
            }
        }

        return n > i ?
            null :
            nthItem;
    },
    */

    findNthToLast(n) {
        let current = list._head;

        for (let i = 0; i < n; i++) {
            if (current.next) {
                current = current.next;
            } else {
                current = null;
            }
        }

        let behind = list._head;

        while (current && current.next) {
            current = current.next;
            behind = behind.next;
        }

        return behind;
    },

    insertFirst(data) {
        const newItem = list.create(data);

        if (!list._head) {
            list._head = newItem;
        } else {
            newItem.next = list._head;
            list._head = newItem;
        }

        return newItem;
    },

    insertLast(data) {
        let listItem = list._head;

        while (listItem !== null && listItem.next) {
            listItem = listItem.next;
        }

        return (listItem === null) ?
            list.insertFirst(data) :
            listItem.next = list.create(data);
    }
};


list.insertFirst(5);
list.insertFirst(42);
list.insertFirst(100);

list.insertLast(7);

list.delete(list.find(100));

list.deleteHead();

list.insertFirst(1972);

console.log(list.findNthToLast(1));

list.deleteList();

console.log(list);

