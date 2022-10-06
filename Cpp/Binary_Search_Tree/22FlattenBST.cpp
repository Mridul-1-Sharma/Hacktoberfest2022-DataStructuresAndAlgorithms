#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node* insertInBST(Node* root, int x){
    if(!root){
        root = new Node(x);
        return root;
    }

    if(x > root->data){
        root->right = insertInBST(root->right, x);
    }else{
        root->left = insertInBST(root->left, x);
    }

    return root;
}

void solve(Node* root, Node* &head){

    if(!root)
        return;

    solve(root->right, head);

    root->right = head;

    if(head)
        head->left = root;

    head = root;

    solve(root->left, head);
}

Node* flattenBST(Node* root){

    Node* head = NULL;

    solve(root, head);
    head->leaf = NULL;

    return head;
}

int main(void){
    Node* root = NULL;

    root = insertInBST(root, 8);
    root = insertInBST(root, 7);
    root = insertInBST(root, 10);
    root = insertInBST(root, 2);
    root = insertInBST(root, 9);
    root = insertInBST(root, 13);


    Node* head = flattenBST(root);

    while(head){
        cout << head->data << " ";
        head = head->right;
    }

    cout << endl;

    return 0;
}