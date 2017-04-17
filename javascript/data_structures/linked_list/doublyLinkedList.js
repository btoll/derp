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

    addNode(data) {
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

    appendNode(data) {
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

    deleteNode(toRemove) {
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

    findNode(data) {
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

    printNodes() {
        let head = list._head;

        while (head) {
            console.log(head.data);
            head = head.next;
        }
    }
};

