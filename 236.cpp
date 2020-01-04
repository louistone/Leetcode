// Author: Tong Xu
// Date: 1/4/2020
// pPatent, qParent vector initialized with value

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
private:
    unordered_map<TreeNode*, TreeNode*> parentMap;

    void dfs(TreeNode* root) {

        if(!root) return;

        if(root->left) {
            parentMap[root->left] = root;
            dfs(root->left);
        }

        if(root->right) {
            parentMap[root->right] = root;
            dfs(root->right);
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        dfs(root);
        vector<TreeNode*> pParent {p}; // this line not initialization cause bug
        vector<TreeNode*> qParent {q}; // this line not initializa
        TreeNode* res;

        while(parentMap.count(p)) {
            pParent.push_back(parentMap[p]);
            p = parentMap[p];
        }

        while(parentMap.count(q)) {
            qParent.push_back(parentMap[q]);
            q = parentMap[q];
        }

        int i = pParent.size() - 1, j = qParent.size() - 1;
        while(i >= 0 && j >= 0) {
            if(pParent[i] == qParent[j]) {
                res = pParent[i];
            }
            else {
                break;
            }
            i--, j--;
        }

        return res;
    }
};
