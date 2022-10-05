#Name=236. Lowest Common Ancestor of a Binary Tree
#Link=https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root ==None or root.val==p.val or root.val==q.val:
            return root
        
        left=self.lowestCommonAncestor(root.left,p,q)
        right=self.lowestCommonAncestor(root.right,p,q)
        
        if left!=None and right!=None:
            return root
        elif left!=None:
            return left
        else:
            return right
