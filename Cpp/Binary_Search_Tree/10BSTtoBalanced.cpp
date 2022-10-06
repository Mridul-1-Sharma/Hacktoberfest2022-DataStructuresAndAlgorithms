#include<iostream>
#include<vector>

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

Node* makeBalance(vector<int> v, int s, int e){

    if(s <= e){
        int mid = (s + e) / 2;

        Node* root = new Node(v[mid]);
        root->left = makeBalance(v, 0, mid - 1);
        root->right = makeBalance(v, mid + 1, e);

        return root;
    }

    return NULL;
}

Node* BSTtoBalanced(Node* root){
    vector<int> inorderVal;

    inorderUtil(root, inorderVal);
    int n = inorderVal.size();

    Node* r = makeBalance(inorderVal, 0, n - 1);

    return r;
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

    root = insertInBST(root, 50);
    root = insertInBST(root, 40);
    root = insertInBST(root, 36);
    root = insertInBST(root, 32);
    root = insertInBST(root, 27);
    root = insertInBST(root, 18);


    inorder(root);
    cout << endl;

    Node* r = BSTtoBalanced(root);

    inorder(root);
    cout << endl;

    return 0;
}