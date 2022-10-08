// Problem name: Path Sum
// Problem link: https://leetcode.com/problems/path-sum/


class Solution {
public:
    
    bool root_to_leaf(TreeNode* root, int Sum){
        
        // root reaches NULL that means we didn't find any path root-to-leaf that add up to sum because if there is any we return from line number '24'
        if(root==NULL)return false;
        
        // because we reach some root value so remaining target sum is sum-root_value
        Sum=Sum-root->val;
        
        // base case when we reach leaf node && Sum becomes '0' specify that we find a path THEREFORE return true
        if(root->left==NULL and root->right==NULL and Sum==0)return true;
        
        // recursive call to LEFT subtree of root && RIGHT subtree of root using or because 
        // if any one of them return true we found a path so return true  && if both of them return false we didn't found any path so return false
        // true or true => true || true or false => true || false or true => true || false or false => false 
        return root_to_leaf(root->left,Sum) or root_to_leaf(root->right,Sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        // EDGE case when tree is empty because there are no root-to-leaf paths THRERFORE return false
        if(root==NULL)return false;
        
        // function call to check if there exist a path root-to-leaf such that adding up values along the path == targetSum
        return root_to_leaf(root,targetSum);
    }
};