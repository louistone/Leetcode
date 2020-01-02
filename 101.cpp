// Author: Tong Xu
// Date: 1/1/2020

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
       height = calHeight(root);
       return bfs(root);
    }

private:
    int height;

    int calHeight(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(calHeight(root->left), calHeight(root->right));
    }

    bool check(vector<string>& v) {
        if(v.empty()) return true;

        int l = 0, r = v.size()-1;
        while(l <= r) {
            if(v[l] != v[r]) return false;
            l++, r--;
        }

        return true;
    }

    bool bfs(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        TreeNode* cur;
        int size;
        nodeQueue.push(root);
        int level = 0;

        while(!nodeQueue.empty() && level < height) {
            size = nodeQueue.size();
            vector<string> tmpVec;
            for(int i = 0; i < size; i++) {
                cur = nodeQueue.front();
                if(cur) tmpVec.push_back(to_string(cur->val));
                else tmpVec.push_back("#");
                nodeQueue.pop();
                cur && cur->left ? nodeQueue.push(cur->left) : nodeQueue.push(NULL);
                cur && cur->right ? nodeQueue.push(cur->right) : nodeQueue.push(NULL);
            }
            if(!check(tmpVec)) return false;

            level++;
        }
        return true;
    }
};
