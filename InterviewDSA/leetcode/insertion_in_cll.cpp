#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
}*head=NULL;

void create_ll(int A[],int n)
{
    head=new Node;
    head->data=A[0];
    head->next=head;
    Node *current=head;

    for(int i=1;i<n;i++)
    {
        Node *temp=new Node;
        temp->data=A[i];
        current->next=temp;
        temp->next=head;
        current=temp;
    }
}

void display()
{
    Node *ptr=head;
    int flag=0;
    while(ptr!=head || flag!=1)
    {
        flag=1;
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<endl;
}

int length()
{
    int length=0;
    Node *ptr=head;
    int flag=0;
    while(ptr!=head || flag!=1)
    {
        flag=1;
        length++;
        ptr=ptr->next;
    }
    return length;
}

void insert(int pos,int data)
{
   Node *temp=new Node;
   temp->data=data;
   if(pos>length())
   {
     cout<<"Invalid Postion";
   }
   else if(pos==1)
   {
       Node *ptr=head;
       while(ptr->next!=head)
       {
           ptr=ptr->next;
       }
       temp->next=head;
       head=temp;
       ptr->next=head;
   }
   else
   {
       Node *ptr=head;
       for(int i=0;i<pos-2;i++)
       {
           ptr=ptr->next;
       }
       temp->next=ptr->next;
       ptr->next=temp;
   }


}

int main()
{
   int A[]={1,2,3,4,5,6};
   create_ll(A,sizeof(A)/sizeof(A[0]));
   display();
   insert(3,0);
  display();
}