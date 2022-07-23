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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        
        dfs(root, v);
        sort(v.begin(), v.end());
        return v[k - 1];
    }
    
    void dfs(TreeNode* node, vector<int>& v) {
        if (!node)
            return;
            
        v.push_back(node->val);
        
        dfs(node->left, v);
        dfs(node->right, v);
    }
};
