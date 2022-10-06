#include<iostream>
#include<vector>
#include<algorithm>

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

void inorderUtil(Node* root, vector<int> &v){
    if(!root)
        return;

    inorderUtil(root->left, v);
    
    v.push_back(root->data);

    inorderUtil(root->right, v);
}

void binaryToBSTUtil(Node* root, vector<int> v, int &i){
    if(!root)
        return;

    binaryToBSTUtil(root->left, v, i);

    root->data = v[i++];

    binaryToBSTUtil(root->right, v, i);    
}

Node* binaryToBST(Node* root){
    vector<int> inorderVal;
    inorderUtil(root, inorderVal);

    sort(inorderVal.begin(), inorderVal.end());

    int i = 0;
    binaryToBSTUtil(root, inorderVal, i);

    return root;
}

void inorder(Node* root){
    if(!root)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

int main(void){

    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right = new Node(9);


    inorder(root);
    cout << endl;

    root = binaryToBST(root);

    inorder(root);
    cout << endl;

    return 0;
}