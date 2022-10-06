class SLL:
    def __init__(self) -> None:
        self.head = None
        self.sz = 0
    def isEmpty(self):
        return self.head == None
    def insertFirst(self,data: int) -> None:
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
        self.sz += 1
    def insertLast(self,data):
        new_node = Node(data)
        if self.isEmpty():
            self.head = Node(data)
            return
        last = self.head
        while last.next:
            last = last.next
        last.next =  new_node
        self.sz += 1
    def insertAfter(self,prevval,value):
        new_node = Node(value)
        target = self.head
        while target:
            if target.data == prevval:
                new_node.next = target.next
                target.next = new_node
                break
            target = target.next
    def insertBefore(self,afterval,val):
        if self.isEmpty():
            self.head = Node(val)
            return
        new_node = Node(val)
        target = self.head
        while target.next:
            if target.next.data == afterval:
                new_node.next = target.next
                target.next = new_node
                break
            target = target.next
    def deleteafter(self, targetvalue: int) -> None:
        curNode = self.head
        while curNode:
            prev = curNode
            curNode = curNode.next
            if prev.data == targetvalue:
                break
        if curNode:
            prev.next = curNode.next
            curNode = None
        else:
            print("last node")
    def deletebefore(self, targetvalue: int) -> None:
        if self.isEmpty():
            self.head = Node(val)
            return
        curNode = self.head
        while curNode.next.next:
            if curNode.next.next.data == targetvalue:
                curNode.next = curNode.next.next
                break
            curNode = curNode.next
    def deleteFirst(self):
        temp = self.head
        if not self.isEmpty():
            self.head = temp.next
            temp = None
            self.sz -= 1
    def deleteLast(self):
        if self.isEmpty():
            print("Error")
            return
        last = self.head
        while last.next:
            prev = last
            last = last.next
        prev.next = last.next
        last = None
        self.sz -= 1
    def listSize(self):
        return self.sz
    def printList(self):
        last = self.head
        while last:
            print(last.data,end=" ")
            last = last.next
        print()

class Node:
    def __init__(self,value = None) -> None:
        self.data = value 
        self.next = None
        return

sll = SLL()
print(sll.isEmpty())
sll.insertFirst(10)
sll.insertFirst(20)
sll.insertFirst(30)
sll.insertAfter(20,120)
#sll.insertBefore(120,70)
sll.insertLast(100)
sll.insertBefore(20,45)
sll.deletebefore(120)
sll.printList()
#sll.deletebefore(70)
