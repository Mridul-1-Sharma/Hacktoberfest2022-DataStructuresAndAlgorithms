#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node(int data){
        this->data = data;
        left = right = next = NULL;
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

void inorder(Node* root){

    if(!root)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

void inorderSuccUtil(Node* root, vector<Node*> &v){

    if(!root)
        return;

    inorderSuccUtil(root->left, v);

    v.push_back(root);

    inorderSuccUtil(root->right, v);
}

Node* inorderSucc(Node* root){

    vector<Node*> inorderVal;

    inorderSuccUtil(root, inorderVal);

    int n = inorderVal.size();

    for(int i = 0; i < n - 1; i++){
        inorderVal[i]->next = inorderVal[i + 1];
    }

    return inorderVal[0];
}

void inorderRecursive(Node* root){

    static Node* next = NULL;

    if(root){

        inorderRecursive(root->right);

        root->next = next;

        next = root;

        inorderRecursive(root->left);
    }
}


int main(void){

    Node* root = NULL;

    root = insertInBST(root, 5);
    root = insertInBST(root, 4);
    root = insertInBST(root, 6);
    root = insertInBST(root, 3);
    root = insertInBST(root, 7);
    root = insertInBST(root, 8);

    inorder(root);
    cout << endl;

    Node* temp = root;
    inorderRecursive(root);

    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}