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

void inorderVal(Node* root, vector<int> &v){
    if(!root)
        return;

    inorderVal(root->left, v);

    v.push_back(root->data);

    inorderVal(root->right, v);
}

int findMedianBST(Node* root){
    vector<int> inVal;
      
    inorderVal(root, inVal);
    
    int n = inVal.size();

    float median;
    
    if(n % 2 == 0){
        int mid = (n - 1) / 2;
        median = (float)(inVal[mid] + inVal[mid + 1]) / 2;
    }else{
        int mid = (n) / 2;
        median = (float)inVal[mid];
    }
    
    return median;
}

int main(void){

    Node* root = NULL;

    root = insertInBST(root, 5);
    root = insertInBST(root, 4);
    root = insertInBST(root, 6);
    root = insertInBST(root, 3);
    root = insertInBST(root, 7);
    root = insertInBST(root, 8);

    cout << findMedianBST(root) << endl;   

    return 0;
}