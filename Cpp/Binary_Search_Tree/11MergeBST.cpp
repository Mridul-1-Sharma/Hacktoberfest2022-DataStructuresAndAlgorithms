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

void BSTtoDLL(Node* root, Node* &head){

    if(!root)
        return;

    BSTtoDLL(root->right, head);

    root->right = head;

    if(head)
        head->left = root;

    head = root;

    BSTtoDLL(root->left, head);
}

Node* mergeBST(Node* root1, Node* root2){

    Node* head = NULL;
    Node* tail = NULL;

    while(root1 and root2){
        if(root1->data < root2->data){
            
            if(!head){
                head = tail = root1;
                root1 = root1->right;
            }

            else{                
                tail->right = root1;
                root1->left = tail;
                tail = tail->right;
                root1 = root1->right;
            }
        }

        else{

            if(!head){
                head = tail = root2;
                root2 = root2->right;
            }

            else{                
                tail->right = root2;
                root2->left = tail;
                tail = tail->right;
                root2 = root2->right;
            }
        }
    }

    while(root1){
        tail->right = root1;
        root1->left = tail;
        tail = tail->right;
        root1 = root1->right;
    }

    while(root2){
        tail->right = root2;
        root2->left = tail;
        tail = tail->right;
        root2 = root2->right;
    }

    return head;
}

int countLLNodes(Node *head){
    int c = 0;
    Node* temp = head;

    while(temp){
        c++;
        temp = temp->right;
    }

    return c;
}

Node* makeBSTFromDLL(Node* &head, int n){
    
    if(n <= 0 or !head)
        return NULL;
    
    Node* left = makeBSTFromDLL(head, n/2);

    Node* root = head;

    root->left = left;
    head = head->right;

    root->right = makeBSTFromDLL(head, n - n/2 - 1);

    return root;
}

Node* mergeTwoBST(Node* root1, Node* root2){

    Node* head1 = NULL;
    BSTtoDLL(root1, head1);
    head1->left = NULL;

    Node* head2 = NULL;
    BSTtoDLL(root2, head2);
    head2->left = NULL;

    Node* head = mergeBST(head1, head2);

    int n = countLLNodes(head);

    return makeBSTFromDLL(head, n);
}

void inorder(Node* root){
    
    if(!root)
        return;

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

int main(void){

    Node* root1 = NULL;

    root1 = insertInBST(root1, 8);
    root1 = insertInBST(root1, 7);
    root1 = insertInBST(root1, 10);
    root1 = insertInBST(root1, 2);
    root1 = insertInBST(root1, 9);
    root1 = insertInBST(root1, 13);

    inorder(root1);
    cout << endl;

    Node* root2 = NULL;

    root2 = insertInBST(root2, 39);
    root2 = insertInBST(root2, 24);
    root2 = insertInBST(root2, 30);
    root2 = insertInBST(root2, 21);
    root2 = insertInBST(root2, 94);
    root2 = insertInBST(root2, 15);

    inorder(root2);
    cout << endl;

    Node* r = mergeBST(root1, root2);

    inorder(r);
    cout << endl;

    return 0;
}