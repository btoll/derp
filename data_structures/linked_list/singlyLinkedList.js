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

    find(data) {
        let item = list._head;

        while (item !== null && item.data !== data) {
            item = item.next;
        }

        return item;
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
    },

    deleteList() {
        while (list._head) {
            const next = list._head.next;
            delete list._head;
            list._head = next;
        }
    }
};


list.insertFirst(5);
list.insertFirst(42);
list.insertFirst(100);
list.insertLast(7);
list.delete(list.find(100));
console.log(list);
list.deleteList();
console.log(list);

