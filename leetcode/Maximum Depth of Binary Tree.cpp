/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rec(TreeNode* curr, int depth) {
        if (curr == NULL)
            return depth - 1;
        if (curr->left == NULL && curr->right == NULL)
            return depth;
        
        depth++;
        int left = rec(curr->left, depth);
        int right = rec(curr->right, depth);
        
        return (left < right) ? right : left;
            
    }
    
    int maxDepth(TreeNode* root) {
        int depth = 1;
        TreeNode* curr = root;
        
        return rec(root, depth);
    }
    
};
