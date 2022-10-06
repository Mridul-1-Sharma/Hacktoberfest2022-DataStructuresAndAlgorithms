#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int data){
        this->data = data;
        right = left = NULL;
    }
};

Node* minVal(Node* root){
    
    Node* temp = root;

    while(temp->left)
        temp = temp->left;

    return temp;
}

Node* deleteBST(Node* root, int x){

    // base case
    if(!root)
        return root;

    if(root->data == x){
        
        // 0 child
        if(!root->left and !root->right){
            delete root;
            return NULL;
        }

        // 1 child
        
        // left child
        if(root->left and !root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if(!root->left and root->right){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left and root->right){
            int min = minVal(root->right)->data;
            root->data = min;
            root->right = deleteBST(root->right, min);
            return root;
        }
    }

    else if(x > root->data){
        root->right = deleteBST(root->right, x);
    }else{
        root->left = deleteBST(root->left, x);
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

int main(void){

    Node* root = NULL;
    root = insertInBST(root, 1);
    root = insertInBST(root, 2);
    root = insertInBST(root, 3);

    inorder(root);
    cout << endl;

    root = deleteBST(root, 3);

    inorder(root);
    cout << endl;

    return 0;
}