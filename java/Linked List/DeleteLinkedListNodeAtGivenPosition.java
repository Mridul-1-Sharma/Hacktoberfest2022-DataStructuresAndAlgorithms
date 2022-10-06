/**
 * A complete working Java program to delete a node in a linked list at a given position 
 */ 
class LinkedList {
	Node head; 

	class Node {
		int data;
		Node next;
		Node(int d)
		{
			data = d;
			next = null;
		}
	}
	public void push(int new_data)
	{
		Node new_node = new Node(new_data);

		new_node.next = head;

		head = new_node;
	}
	void deleteNode(int pos)
	{
		if (head == null)
			return;

		Node temp = head;

		if (pos == 0) {
			head = temp.next; 
			return;
		}
		for (int i = 0; temp != null && i < pos - 1;
			i++)
			temp = temp.next;

		if (temp == null || temp.next == null)
			return;
		Node next = temp.next.next;

		temp.next= next; 
	}

	public void printList()
	{
		Node tnode = head;
		while (tnode != null) {
			System.out.print(tnode.data + " ");
			tnode = tnode.next;
		}
	}

	public static void main(String[] args)
	{
		LinkedList llist = new LinkedList();

		llist.push(6);
		llist.push(1);
		llist.push(9);
		llist.push(2);
		llist.push(8);

		System.out.println("Created Linked list is: ");
		llist.printList();

		llist.deleteNode(3); 

		System.out.println("Linked List after Deletion at position 3: ");
		llist.printList();
	}
}

/**
Example:

Input: position = 3, Linked List = 8->2->3->1->6
Output: Linked List = 8->2->3->6

Input: position = 1, Linked List = 8->2->9->1->6
Output: Linked List =  8->9->1->7
*/
