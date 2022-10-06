#include<iostream>
#include<climits>

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

bool validateBST(Node* root, int min, int max){

    if(!root)
        return true;

    if(root->data >= min and root->data <= max){
        bool left = validateBST(root->left, min, root->data);
        bool right = validateBST(root->right, root->data, max);

        return (left and right);
    }else
        return false;
}

int main(void){
    Node* root = NULL;

    root = insertInBST(root, 5);
    root = insertInBST(root, 7);
    root = insertInBST(root, 2);
    root = insertInBST(root, 8);

    cout << validateBST(root, INT_MIN, INT_MAX) << endl;
    return 0;
}