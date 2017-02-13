/* eslint-disable no-console */

const list = {
    _head: null,

    create(data) {
        return {
            next: null,
            data: data
        };
    },

    add(data) {
        const newItem = list.create(data);

        if (!list._head) {
            list._head = newItem;
        } else {
            newItem.next = list._head;
            list._head = newItem;
        }

        return newItem;
    },

    append(data) {
        let listItem = list._head;

        while (listItem !== null && listItem.next) {
            listItem = listItem.next;
        }

        return (listItem === null) ?
            list.add(data) :
            listItem.next = list.create(data);
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
list.add(100);
list.add(3);
list.add(17);

// list.delete(list.find(100));

// list.deleteHead();


// console.log(list.findNthToLast(1));

// list.deleteList();

// console.log(list);
list.print();

