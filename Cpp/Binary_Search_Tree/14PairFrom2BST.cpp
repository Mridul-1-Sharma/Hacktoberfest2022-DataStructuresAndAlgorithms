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

int pairsFromBST(Node* root1, Node* root2, int key){

    vector<int> inVal1, inVal2;

    inorderVal(root1, inVal1);
    inorderVal(root2, inVal2);

    int n = inVal1.size();
    int m = inVal2.size();

    int i = 0, j = m - 1;

    int count = 0;

    while(i < j){
        
        int sum = inVal1[i] + inVal2[j];

        if(sum == key){
            count++;
            i++;
            j--;
        }else if(sum > key){
            j--;
        }else{
            i++;
        }
    }

    return count;
}

int main(void){
    Node* root = NULL;

    root = insertInBST(root, 5);
    root = insertInBST(root, 4);
    root = insertInBST(root, 6);
    root = insertInBST(root, 3);
    root = insertInBST(root, 7);
    root = insertInBST(root, 8);

    Node* root1 = NULL;

    root1 = insertInBST(root, 5);
    root1 = insertInBST(root, 4);
    root1 = insertInBST(root, 6);
    root1 = insertInBST(root, 3);
    root1 = insertInBST(root, 7);
    root1 = insertInBST(root, 8);

    cout << pairsFromBST(root, root1, 7) << endl;

    return 0;
}