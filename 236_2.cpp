// Author: Tong Xu
// Date: 1/4/2020
// All cases: ususally 2*2, take all of them into consideration

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root || root == p || root == q) return root;

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        if(l && r) return root;
        if(!l && !r) return NULL; // miss this line of code and cause the bug

        return l ? l : r;
    }
};
