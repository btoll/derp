class Node:
    ''' represents each node in a linked list '''
    def __init__(self, data=None):
        self.next = None
        self.data = data

    def __str__(self):
        return str(self.data)

class LinkedList:
    ''' simple linked list implementation '''

    def __init__(self):
        self._head = None

    def append(self, data):
        if not self._head:
            self._head = Node(data)
        else:
            node = self._head

            while node and node.next:
                node = node.next

            node.next = Node(data)

    def getHead(self):
        return self._head

    def getNode(self, data):
        node = self._head
        found = None

        if (node is None):
            return

        if node.data is data:
            return node

        while node and node.next:
            if node.data is data:
                found = node
                break

            node = node.next

        return found

    def remove(self, data):
        node = self._head

        if (node is None):
            return

        if node.data is data:
            self._head = node.next
            return

        node = self._head.next
        prev = self._head

        while node and node.next:
            if node.data is data:
                prev.next = node.next
                break

            prev = node
            node = node.next

########################################################

l = LinkedList()

l.append(0)
l.append(1)
l.append(2)
l.append(3)
l.append(4)
l.append(5)
l.append(6)

print(l.getHead()) # 0

l.remove(0)

print(l.getHead()) # 1

l.remove(5)

print(l.getNode(4).next) # 6

