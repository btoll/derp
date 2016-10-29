/* eslint-disable no-console */

const list = {
    _head: null,

    create(data) {
        return {
            next: null,
            data: data
        };
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
list.insertLast(7);
console.log(list);

