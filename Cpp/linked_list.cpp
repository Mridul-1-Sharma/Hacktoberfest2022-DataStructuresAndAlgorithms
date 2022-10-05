#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define  vvi vector<vi>
#define in cin >>
#define out cout <<
#define ll long long int
#define new_l cout << "\n";
#define ull unsigned long long int

class node{
   public:
   int data;
   node* next;
   // constructor
   node(int val){
       data=val;
       next=NULL;
   }

};


// insert at head
 void insertAtHead(node* &head, int val){
     node*n=new node(val);
     n->next=head;
     head=n;

 }
 
 // insert at tail
 void insertAtTail(node* &head, int val){
     
     node* n=new node(val);
     if(head==NULL){
         head=n;
         return;
     }
     node*temp= head;
     while(temp->next!=NULL){
         temp=temp->next;
     }
     temp->next=n;
 }
 
 // insert node at index
 void insertAtIndex(int pos, node* &head, int val){
     
       int idx=1;
       node* temp=head;
       node* n=new node(val);
       if(pos==1){
          insertAtHead(head,val);
          return;
       }

       while(idx<pos-1){
           idx++;
           temp=temp->next;
       }
       n->next=temp->next;
       temp->next=n;

 }
 
 // print linked list
 void printLL(node* head){
     if(head==NULL){
         out "NULL";
         return;
     } 
     out head->data<<" -> ";
     printLL(head->next);
 }

// to delete node at specific position
 void deleteNode(int pos, node* &head){
     if(pos==1){
         node*ref=head;
         head=head->next;
         delete ref;
         return;
     }
     node*prev=NULL;
     int x=1;
     node*curr=head;
     while(x!=pos){
         prev=curr;
         curr=curr->next;
         x++;
     }
     prev->next=curr->next;
     delete curr;
 }
 
 // reverse linkedlist
 void reverse(node* &head){
     if(head==NULL)return;
     if(head->next==NULL)return;
     node*prev=NULL;
     node*curr=head;
     node* nxt=head->next;
     while(curr->next!=NULL){
         curr->next=prev;
         prev=curr;
         curr=nxt;
         nxt=curr->next;
     }
     curr->next=prev;
     head=curr;
 }
 
 // reverse linkedlist by recursion
 void reverseByRecursion(node* &head,node*curr, node*prev){
     // base
     if(curr==NULL){
         head=prev;
         return;
     }
     reverseByRecursion(head,curr->next,curr);
     curr->next=prev;
 }
 
 // delete node by value
 void deleteNode(node* &head, int val){
     if(head->data==val){
         head=head->next;
         return;
     }
     node*temp=head;
     while(temp!=NULL){
         if(temp->next->data==val){
            node*toDelete=temp->next;
            temp->next=temp->next->next;
            delete toDelete;
            break;
         }
         temp=temp->next;
     }
 }
 
 // to print linkedlist in reverse order
 void print_reverse(node* head){
     if(!head){
         out "NULL ";
         return;
     }
     print_reverse(head->next);
     out " <- "<<head->data;
 }
 
 // find middle node
 node* middleNode(node* head) {
     // in case of even no. of node second element considered
      node* h1 = head, *h2 = head;
        while(h2 and h2->next and h2->next->next){
            h1= h1->next;
            h2 = h2->next->next;
        }
        if(h1 ==  h2){
            if(h1->next)return h1->next;
            else h1;
        }
        if(!h2->next)return h1;
        else return h1->next;
}
 
 // delete middle node
 void deleteMiddle(node* head) {
     // in case of even no. of node second node deleted
        if(!head->next)return ;
        if(!head->next->next){
            head->next=NULL;
            return ;
        }
        node* fast= head, *slow=head;
        while(fast and fast->next and fast->next->next){
            
            slow=slow->next;
            fast=fast->next->next;
        }
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        slow->data=slow->next->data;
        slow->next=slow->next->next;
       
    }
int main()
{  

    node* n = new node(1);
    
    for(int i = 2;i<5; i++){
        insertAtTail(n,i);
    }
    cout<<middleNode(n)->data<<"\n";
    printLL(n);
    
    


	return 0;
}