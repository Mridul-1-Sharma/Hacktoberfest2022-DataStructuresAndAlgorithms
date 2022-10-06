#include<iostream>
#include<unordered_set>

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

void solve(Node* root, unordered_set<int> &all, unordered_set<int> &leaf){

    if(!root)
        return;

    all.insert(root->data);

    if(!root->left and !root->right)
        leaf.insert(root->data);

    solve(root->left, all, leaf);
    solve(root->right, all, leaf);
}

bool isDeadEnd(Node* root){

    unordered_set<int> all_nodes, leaf_nodes;

    solve(root, all_nodes, leaf_nodes);

    for(auto i = leaf_nodes.begin(); i != leaf_nodes.end(); i++){
        int x = *i;
        if(all_nodes.find(x + 1) != all_nodes.end() and all_nodes.find(x - 1) != all_nodes.end()){
            return true;
        }
    }

    return false;
}

int main(void){

    Node* root = NULL;

    root = insertInBST(root, 8);
    root = insertInBST(root, 7);
    root = insertInBST(root, 10);
    root = insertInBST(root, 2);
    root = insertInBST(root, 9);
    root = insertInBST(root, 13);

    cout << isDeadEnd(root) << endl;

    return 0;
}