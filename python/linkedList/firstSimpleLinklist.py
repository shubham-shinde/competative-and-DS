class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class linkedList:
    def __init__(self):
        self.head = None

    def printList(self):
        temp = self.head
        while(temp):
            print(temp.data)
            temp = temp.next

    def push(self, new_data):
        self.temp = self.head
        self.head = Node(new_data)
        self.head.next = self.temp

    def append(self, new_data):
        temp = self.head
        if not self.head:
            self.head = Node(new_data)
            return
        while(temp.next):
            temp = temp.next
        temp.next = Node(new_data)

    def instertAfter(self, prevNode, new_data):
        if not prevNode:
            print 'previous node should be present in linked list'
            return
        temp = prevNode.next
        prevNode.next = Node(new_data)
        prevNode.next.next = temp


    def pop(self):
        self.head = self.head.next

    def count(self):
        temp = self.head
        count = 0
        while(temp):
            count += 1
            temp = temp.next
        return count



if __name__ == '__main__':
    llist = linkedList()
    llist.head = Node(1)
    second = Node(2)
    third = Node(3)

    #linlking of lists
    llist.head.next = second
    second.next = third
    llist.push(7)
    llist.pop()
    llist.append(8)
    llist.instertAfter(llist.head.next, 0)
    llist.printList()
    print llist.count()
