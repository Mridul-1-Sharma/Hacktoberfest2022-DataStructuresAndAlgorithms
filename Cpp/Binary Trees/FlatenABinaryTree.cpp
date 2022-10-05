//Flaten a Binary Tree
//left of each node will be null
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printTree(Node* node)
{
    if(node == NULL)
    return;

    cout<<node->data<<" ";
    printTree(node->left);
    printTree(node->right);
}
void printInOrder(Node* root)
{
    if(root==NULL)
    return;

    printInOrder(root->left);

    cout<<root->data<<" ";

    printInOrder(root->right);

}

int searchIn(int in[],int start,int end,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(in[i]==curr)
        return i;
    }
    return -1;
}

Node* treePreIn(int pre[], int in[], int start, int end)
{
    if(start>end)
    return NULL;

    static int idx = 0;
    int curr = pre[idx];
    idx++;
    Node* node = new Node(curr);

    if(start == end)
    return node;

    int pos = searchIn(in,start,end,curr);
    node->left = treePreIn(pre,in,start,pos-1);
    node->right = treePreIn(pre,in,pos+1,end);

    return node;
}

void treeFlatten(Node* root)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))
    return;

    if(root->left != NULL)
    {
        treeFlatten(root->left);
        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        Node* t = root->right;
        while(t->right!=NULL)
        t = t->right;

        t->right = temp;
    }
    treeFlatten(root->right);
}
//         4
//     9       5
//   1  3       6

int main ()
{
    int preOrder[] = {4,9,1,3,5,6};
    int inOrder[] = {1,9,3,4,5,6};

    Node* root = treePreIn(preOrder,inOrder,0,5);
    // cout<<root->right->right->data<<endl;
    printTree(root);
    cout<<endl;

    treeFlatten(root);
    // cout<<root->data;
    printInOrder(root);
}