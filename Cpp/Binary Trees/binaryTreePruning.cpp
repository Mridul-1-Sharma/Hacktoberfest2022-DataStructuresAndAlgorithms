/// Given the root of a binary tree, 
/// return the same tree where every subtree(of the given tree) not containing a 1 has been removed.
#include <iostream>
using namespace std;

class TreeNode
{
    public :
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *pruneTree(TreeNode *root)
{
    if (!root)
        return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->val == 0 && !root->right && !root->left)
        return nullptr;
    return root;
}

void preOrder(TreeNode *root){
    if(!root) return;
    cout<<(root->val)<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    TreeNode *root = new TreeNode(
        1, 
        nullptr,
        new TreeNode(
            0,new TreeNode(0),new TreeNode(1)
        )
    );
    preOrder(root);
    TreeNode *newNode = pruneTree(root);
    cout<<endl;
    preOrder(newNode);
    
}
