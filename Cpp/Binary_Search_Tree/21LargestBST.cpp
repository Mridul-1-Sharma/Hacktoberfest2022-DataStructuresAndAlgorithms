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

struct info{
    int mini;
    int maxi;
    bool isBST;
    int size;
};

info solve(Node* root, int &ans){

    if(!root)
        return {INT_MAX, INT_MIN, true, 0};

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info curr;

    curr.size = left.size + right.size + 1;
    curr.mini = min(root->data, left.mini);
    curr.maxi = max(root->data, right.maxi);

    if(left.isBST and right.isBST and (root->data > left.maxi and root->data < right.mini))
        curr.isBST = true;
    else
        curr.isBST = false;

    if(curr.isBST)
        ans = max(ans, curr.size);

    return curr;
}

int largestBSTinBinaryTree(Node* root){

    int ans = 0;
    solve(root, ans);

    return ans;
}

int main(void){

    Node* root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(4);
    root->left->left = new Node(6);
    root->left->right = new Node(8);

    cout << largestBSTinBinaryTree(root) << endl;

    return 0;
}