#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
 
        
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}
 

struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
int main()
{
    struct node* root = newNode(10);
 
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
 
    printf("Height of tree is %d", height(root));
  
    return 0;
}
