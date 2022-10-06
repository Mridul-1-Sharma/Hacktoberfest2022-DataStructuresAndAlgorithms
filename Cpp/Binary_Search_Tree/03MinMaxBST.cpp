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

    if(x > root -> data){
        root->right = insertInBST(root->right, x);
    }else{
        root->left = insertInBST(root->left, x);
    }

    return root;
}

int minVal(Node* root){
    Node* temp = root;

    while(temp->left)
        temp = temp->left;

    return temp->data;
}

int maxVal(Node* root){
    Node* temp = root;

    while(temp->right)
        temp = temp->right;

    return temp->data;
}

int main(void){

    Node* root = NULL;
    root = insertInBST(root, 1);
    root = insertInBST(root, 2);
    root = insertInBST(root, 3);

    cout << minVal(root) << endl;
    cout << maxVal(root) << endl;

    return 0;
}