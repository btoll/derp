
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

// 17 -> 3 -> 100 -> 42 -> 5 -> 1972

list.addNode(1972);
list.addNode(5);
list.addNode(42);
const n100 = list.addNode(100);
list.addNode(3);
list.addNode(17);
const n666 = list.appendNode(666);

list.insertAfter(n100, 200);
// list.print();

// 17 -> 3 -> 100 -> 200 -> 42 -> 5 -> 1972 -> 666

list.printNodes();

console.log(isCyclic(list));
n666.next = n100;
console.log(isCyclic(list));

