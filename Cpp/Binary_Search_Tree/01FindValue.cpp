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

bool findValueBSTIterative(Node* root, int x){
  Node* temp = root;

  while(!temp){
    if(temp->data == x)
      return true;

    if(x > temp->data)
      temp = temp->right;
    else
      temp = temp->left;
  }

  return false;
}

bool findValueBST(Node* root, int x){
  
  if(!root)
    return false;

  if(root->data == x)
    return true;

  if(x > root->data)
    return findValueBST(root->right, x);
  else
    return findValueBST(root->left, x);
}

int main(void){

  Node* root = new Node(10);
  root->left = new Node(7);
  root->right = new Node(15);
  root->left->left = new Node(5);
  root->left->right = new Node(9);
  root->right->left = new Node(13);
  root->right->right = new Node(17);

  cout << findValueBST(root, 21) << endl;

  return 0;
}
