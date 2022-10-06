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

void inorderPrecSucc(Node* root, Node* &pre, Node* &suc, int key){
    
    if(!root)
        return;

    if(root->data == key){
        
        if(root->left){
            Node* temp = root->left;
            while(temp->right)
                temp->right;
            
            pre = temp;
        }

        if(root->right){
            Node* temp = root->right;
            while(temp->left)
                temp->left;

            suc = temp;
        }

        return;
    }

    if(key > root->data){
        pre = root;
        inorderPrecSucc(root->right, pre, suc, key);
    }else{
        suc = root;
        inorderPrecSucc(root->left, pre, suc, key);
    }

}

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

void inorder(Node* root){

    if(!root)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

int main(void){
    Node* root = NULL;

    root = insertInBST(root, 1);
    root = insertInBST(root, 9);
    root = insertInBST(root, 6);

    inorder(root);
    cout << endl;

    Node* pre = NULL;
    Node* suc = NULL;

    inorderPrecSucc(root, pre, suc, 6);

    cout << pre->data << endl;
    cout << suc->data << endl;

    return 0;
}