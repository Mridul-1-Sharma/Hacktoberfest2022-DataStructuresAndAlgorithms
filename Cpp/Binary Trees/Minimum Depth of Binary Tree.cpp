// Problem name: Minimum Depth of Binary Tree
// Problem link: https://leetcode.com/problems/minimum-depth-of-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /* recursive solution*/
    //int minDepth(TreeNode* root) {
    //    if(root == NULL){
    //        return 0;
    //    }else if(root->left == NULL){
    //        return minDepth(root->right) + 1;
    //    }else if(root->right == NULL){
    //        return minDepth(root->left) + 1;
    //    }
    //    int lh = minDepth(root->left);
    //    int rh = minDepth(root->right);
    //    int ans = min(lh, rh) + 1;
    //    return ans;
    //}

    /*iterative solution using queue*/
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> q;
        TreeNode* flag = new TreeNode(-1);
        int depth = 1;
        q.push(root);
        q.push(flag);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp == flag){
                ++depth;
                if(!q.empty()){
                    q.push(flag);
                }
                continue;
            }
            if(tmp->left == NULL && tmp->right == NULL){
                break;
            }
            if(tmp->left != NULL ){
                q.push(tmp->left);
            }
            if(tmp->right != NULL){
                q.push(tmp->right);
            }
        }
        return depth;
    }
};