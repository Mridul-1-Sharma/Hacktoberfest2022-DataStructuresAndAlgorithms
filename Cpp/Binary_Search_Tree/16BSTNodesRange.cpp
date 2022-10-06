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

void solve(Node* root, int &i, int mini, int maxi){

    if(!root)
        return;

    solve(root->left, i, mini, maxi);

    if(root->data >= mini and root->data <= maxi)
        i++;

    solve(root->right, i, mini, maxi);
}

int getCount(Node* root, int l, int h){

    int i = 0;

    solve(root, i, l, h);

    return i;
}

int main(void){

    Node* root = NULL;

    root = insertInBST(root, 5);
    root = insertInBST(root, 4);
    root = insertInBST(root, 6);
    root = insertInBST(root, 3);
    root = insertInBST(root, 7);
    root = insertInBST(root, 8);

    cout << getCount(root, 3, 6) << endl;

    return 0;
}