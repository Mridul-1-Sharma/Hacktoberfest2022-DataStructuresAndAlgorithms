#include <bits/stdc++.h>
using namespace std;


class Node
{
	public:
	int data;
	Node *next;
};


void fun1(Node* head)
{
	if(head == NULL)
		return;
	
	fun1(head->next);
	cout << head->data << " ";
}


void fun2(Node* start)
{
	if(start == NULL)
		return;
	cout<<start->data<<" ";
	
	if(start->next != NULL )
		fun2(start->next->next);
	cout << start->data << " ";
}


void push(Node** head_ref, int new_data)
{

	Node* new_node = new Node();
	

	new_node->data = new_data;
	

	new_node->next = (*head_ref);
	

	(*head_ref) = new_node;
}

int main()
{

	Node* head = NULL;
	

	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	
	cout<<"Output of fun1() for list 1->2->3->4->5 \n";
	fun1(head);
	
	cout<<"\nOutput of fun2() for list 1->2->3->4->5 \n";
	fun2(head);

	return 0;
}



