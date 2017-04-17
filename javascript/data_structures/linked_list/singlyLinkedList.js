const list = {
    _head: null,

    create(data) {
        return {
            next: null,
            data: data
        };
    },

    addNode(data) {
        const newItem = list.create(data);

        if (!list._head) {
            list._head = newItem;
        } else {
            newItem.next = list._head;
            list._head = newItem;
        }

        return newItem;
    },

    appendNode(data) {
        let listItem = list._head;

        while (listItem !== null && listItem.next) {
            listItem = listItem.next;
        }

        return (listItem === null) ?
            list.addNode(data) :
            listItem.next = list.create(data);
    },

    deleteNode(toRemove) {
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

    findNode(data) {
        let item = list._head;

        while (item !== null && item.data !== data) {
            item = item.next;
        }

        return item;
    },

    insertAfter(prev, data) {
        const newNode = list.create(data);

        newNode.next = prev.next;
        prev.next = newNode;

        return newNode;
    },

    printNodes() {
        let head = list._head;

        while (head) {
            console.log(head.data);
            head = head.next;
        }
    }
};

module.exports = list;

