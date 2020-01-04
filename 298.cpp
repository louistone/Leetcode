//Author: Tong Xu
//Date: 01/03/2020
// Solution: preorder traversal

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
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        int cur = 0, maxLen = 0;
        dfs(root, cur, maxLen, root->val);
        return maxLen;
    }

private:
    void dfs(TreeNode* root, int cur, int& maxLen, int comp) { // bug: not pass cur as a reference
        if(!root) return;
        if(root->val == comp) cur++;
        else cur = 1;
        maxLen = max(maxLen, cur);
        dfs(root->left, cur, maxLen, root->val+1);
        dfs(root->right, cur, maxLen, root->val+1);
    }
};
