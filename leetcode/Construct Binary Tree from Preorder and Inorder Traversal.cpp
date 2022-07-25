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
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size() || !inorder.size())
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[0]);
        int mid = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        
        vector<int> left(inorder.begin(), inorder.begin() + mid);
        vector<int> right(inorder.begin() + mid + 1, inorder.end());
        preorder.erase(preorder.begin());
        
        root->left = buildTree(preorder, left);
        root->right = buildTree(preorder, right);
        
        return root;
    }
};
