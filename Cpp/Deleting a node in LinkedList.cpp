// Problem Link : https://leetcode.com/problems/delete-node-in-a-linked-list/

#include <bits/stdc++.h>

using namespace std;

class ListNode {
  public:
    int val;
  ListNode * next;
  ListNode(int x) {
    val = x;
    next = nullptr;
  }
};

ListNode * head, * tail; 

void PrintList() 
{
  ListNode * curr = head;
  for (; curr != nullptr; curr = curr -> next)
    cout << curr -> val << "-->";
  cout << "null" << endl;
}

void InsertatLast(int value) 
{

  ListNode * newnode = new ListNode(value);
  if (head == nullptr)
    head = newnode, tail = newnode;
  else
    tail = tail -> next = newnode;
}

void DeleteLast() {
  if (head == nullptr)
    cout << "There are no nodes to delete in LinkedList" << endl;

  if (head -> next == nullptr) {
    delete head;
    head = nullptr;
  } else {


    ListNode * curr = head, * prev = nullptr;
    while (curr -> next != nullptr) {
      prev = curr;
      curr = curr -> next;
    }


    prev -> next = nullptr;


    delete curr;
  }
}

int main() {
  InsertatLast(10);
  InsertatLast(20);
  InsertatLast(30);
  InsertatLast(40);
  cout << "LinkedList before Deleting Last Node : " << endl;
  PrintList();
  DeleteLast();
  cout << "LinkedList after Deleting Lastt Node : " << endl;
  PrintList();
  return 0;
}