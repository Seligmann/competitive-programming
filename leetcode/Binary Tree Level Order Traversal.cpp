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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        vector<TreeNode*> nodes = {root};
        
        while (nodes.size()) {
            vector<int> vals;
            vector<TreeNode*> nextLevel;
            
            for (auto node: nodes) {
                if (!node) continue;
                vals.push_back(node->val);
                nextLevel.push_back(node->left);
                nextLevel.push_back(node->right);
            }
            
            if (vals.size())
                ret.push_back(vals);
            
            nodes.clear();
            nodes = nextLevel;
            
        }
        return ret;
    }
    
    
};
