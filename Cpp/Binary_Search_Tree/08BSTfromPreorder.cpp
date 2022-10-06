#include<iostream>
#include<vector>
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

Node* solve(vector<int> &pre, int mini, int maxi, int &i){

    if(i >= pre.size())
        return NULL;

    if(pre[i] < mini or pre[i] > maxi)
        return NULL;

    Node* root = new Node(pre[i++]);

    root->left = solve(pre, mini, root->data, i);
    root->right = solve(pre, root->data, maxi, i);

    return root;
}

Node* BSTfromPreorder(vector<int> pre){

    int i = 0;
    int mini = INT_MIN;
    int maxi = INT_MAX;

    return solve(pre, mini, maxi, i);
}

void inorder(Node* root){
    if(!root)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

int main(void){
    vector<int> pre { 10, 5, 1, 7, 40, 50 };
    Node* root = BSTfromPreorder(pre);

    inorder(root);
    cout << endl;
    return 0;
}