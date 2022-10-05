//#include<iostream>
//int sum(int* arr,int n)
//{
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum = sum + arr[i];
//
//	}
//	return sum;
//}
//struct node
//{
//	int data;
//	node* next;
//};
//class CLL
//{
//	node* head;
//
//public:
//	CLL()
//	{
//		head = NULL;
//	}
//
//	void insertAtBegin(int val)
//	{
//		node* newNode = new node;
//		newNode->data = val;
//
//		if (head == NULL)               //if list is empty
//		{
//			newNode->next = newNode;         //create a new node, the new node is the head as well as the next of the head i.e. only one node in circle 
//			head = newNode;
//			return;
//		}
//		node* curr = new node;                     //if list is not empty traverse to the last node 
//		curr = head;
//
//		do
//		{
//			curr = curr->next;
//
//		} while (curr->next != head);
//		curr->next = newNode;              //at the last node we insert a node before the head that is the next of last node and the new head 
//		newNode->next = head;
//		head = newNode;
//
//	}
//
//	void DeleteAtBegin()
//	{
//		node* newnode = new node;
//		newnode = head;
//		
//	
//		while (newnode->next != head)
//		{
//
//			newnode = newnode->next;
//		}
//
//		node* temp = new node;
//		temp = head;
//
//		head = head->next;
//		newnode->next = head;
//
//		delete temp;
//		temp = NULL;
//	}
//
//	void DeleteAtEnd()
//	{
//		
//
//		if (head == NULL)              //if head is NULL there is nothing to delete 
//		{ 
//			return;
//		}
//		else
//		{
//			node* curr = new node;               //if list is not empty traverse to the last node 
//			curr = head;
//			node* prev = NULL;
//			do
//			{
//				prev = curr;
//				curr = curr->next;
//				
//
//			} while (curr->next != head);
//
//			node* temp = new node;           //delete the last node by using a temp pointer 
//			temp = curr;
//
//			prev->next = head;
//			curr = prev;
//			delete temp;
//			temp = NULL;
//		}
//
//
//	}
//	void DisplayCircularLinkedList()
//	{
//		node* curr = new node;
//		curr = head;
//		do
//		{
//			std::cout << curr->data << " ";
//			curr = curr->next;
//		} while (curr != head);                      //traverse and display the data of the list until the curr pointer reaches the head again
//		std::cout << std::endl;
//
//	}
//	bool isempty()
//	{
//
//		if (head == NULL)
//			return true;
//
//		return false;
//	}
//	
//	int RRC(int* arr, CLL& list,int time_slice,int n)
//	{
//		int time = 0;
//		int s = sum(arr,n);
//		while (time < s)
//		{
//			for (int i = 0; i < n; i++)
//			{
//				if (arr[i] <= time_slice && arr[i] != 0)
//				{
//					time += arr[i];
//					arr[i] = 0;
//					list.DeleteAtEnd();
//				}
//				else
//				{
//					if (arr[i] != 0)
//					{
//						arr[i] = arr[i] - time_slice;
//						time += time_slice;
//					}
//
//				}
//
//			}
//
//		}
//
//		return time;
//	}
//
//};
//
//
//int main()
//{
//
//
//	CLL list;
//	
//	int n;
//	std::cin >> n;
//
//	int* exe_time = new int[n];
//
//	for (int i = 0; i < n; i++)
//	{
//		list.insertAtBegin(i + 1);
//		std::cin >> exe_time[i];
//	}
//
//	int time_slice;
//
//	std::cin >> time_slice;
//
//	
//	list.DisplayCircularLinkedList();
//	std::cout << std::endl;
//
//	std::cout<<"Execution time:\n"<<list.RRC(exe_time, list, time_slice, n);
//
//
//	return 0;
//
//}