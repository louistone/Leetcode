/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// da lao's solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return dfs(root->left, root->right);
    }

private:
    bool dfs(TreeNode* left, TreeNode* right) {
        if(!left && !right) return true;
        if(left && right && left->val != right->val) return false;
        if((left && !right) || (!left && right)) return false;
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};
