// Author: Tong Xu
// Date: 01/04/2020

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        vector<int> nums = generateNums(head);
        return generateTree(nums, 0, nums.size()-1);
    }

private:
    vector<int> generateNums(ListNode* head) {
        vector<int> numVec;
        while(head) {
            numVec.push_back(head->val);
            head = head->next;
        }
        return numVec;
    }

    TreeNode* generateTree(vector<int>& nums, int l, int r) {
        if(l > r) return NULL;
        int mid = l + (r-l)/2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = generateTree(nums, l, mid-1);
        root->right = generateTree(nums, mid+1, r);

        return root;
    }
};
