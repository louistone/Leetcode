// Author: Tong Xu
// Date: 1/1/2020
// Location: MCC
// Dfs solution for 101 Symmetric Tree
// Deep copy to avoid pointer bug

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
    bool isSymmetric(TreeNode* root) {

        if(!root) return true;
        TreeNode* copy = copyNode(root); // deep copy to avoid pointer bugs

        reverse(copy);
        bool val = true;
        check(root, copy, val);
        return val;
    }

private:
    TreeNode* copyNode(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* copy = new TreeNode(root->val);
        copy->left = copyNode(root->left);
        copy->right = copyNode(root->right);
        return copy;
    }

    void check(TreeNode* node1, TreeNode* node2, bool& val) {
        if(!node1 && !node2) return;

        if((!node1 && node2) || (node1 && !node2)) {
            val = val && false;
            return;
        }

        check(node1->left, node2->left, val);
        if(node1->val != node2->val) {
            val = val && false;
            return;
        }
        check(node1->right, node2->right, val);
    }

    // below function reverse the tree
    void reverse(TreeNode* root) {
        if(!root) return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        reverse(root->left);
        reverse(root->right);
    }
};
