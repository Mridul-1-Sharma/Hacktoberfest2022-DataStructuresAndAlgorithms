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

Node* LCAIterative(Node* root, int p, int q){
    Node* temp = root;

    while(temp){
        if(temp->data > p and temp->data > q){
            temp = temp->left;
        }
        else if(temp->data < p and temp->data < q){
            temp = temp->right;
        }
        else
            return temp;
    }
}

Node* LCA(Node* root, int p, int q){

    if(!root)
        return NULL;
    
    if(root->data > p and root->data > q){
        return LCA(root->left, p, q);
    }else if(root->data < p and root->data < q){
        return LCA(root->right, p, q);
    }

    return root;
}

int main(void){
    Node* root = NULL;

    root = insertInBST(root, 5);
    root = insertInBST(root, 4);
    root = insertInBST(root, 6);
    root = insertInBST(root, 3);
    root = insertInBST(root, 7);
    root = insertInBST(root, 8);

    cout << LCAIterative(root, 7, 8)->data << endl;

    return 0;
}