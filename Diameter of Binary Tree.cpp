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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode* node, int& res) {
        if (node == NULL)
            return 0;
        
        int left = dfs(node->left, res);
        int right = dfs(node->right, res);
        res = max(left + right, res);
        
        return max(left, right) + 1;
    }
};
