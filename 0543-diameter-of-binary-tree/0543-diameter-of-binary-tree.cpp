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
    int res = 0;
    int maxDepth(TreeNode* root) {
        int m = 0;
        if(!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        m = 1 + max(left,right);
        res = max(res, left + right);
        return m;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return res;

        
    }
};
