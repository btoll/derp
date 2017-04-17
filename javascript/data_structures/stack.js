const stack = {
    _head: null,

    create(data) {
        return {
            next: null,
            data: data
        };
    },

    deleteStack() {
        while (stack._head) {
            const next = stack._head.next;
            delete stack._head;
            stack._head = next;
        }
    },

    pop() {
        let item;

        if ((item = stack._head)) {
            stack._head = item.next;
            item.next = null;
            return item;
        }

        return false;
    },

    push(data) {
        const newItem = stack.create(data);

        if (!stack._head) {
            stack._head = newItem;
        } else {
            newItem.next = stack._head;
            stack._head = newItem;
        }

        return newItem;
    }
};

stack.push(5);
stack.push(7);
stack.push(42);
console.log(stack.pop());
stack.deleteStack();

