#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int val) {
            num = val;
            next = NULL;
        }
};

void insertNode(node* head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

bool isPalindrome(node* head) {
    vector<int> arr;
    while(head != NULL) {
        arr.push_back(head->num);
        head = head->next;
    }
    for(int i=0;i<arr.size()/2;i++) 
        if(arr[i] != arr[arr.size()-i-1]) return false;
    return true;
}

int main() {
    node* head = NULL;
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,2);
    insertNode(head,1);
    isPalindrome(head)? cout<<"True" : cout<<"False";
    return 0;
}
