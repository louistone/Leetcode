// Author: Tong Xu
// Date: 1/3/2020
// 2 pass solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int calListLength(ListNode* head) {
        if(!head) return 0;
        return 1 + calListLength(head->next);
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = calListLength(head);
        int rem = len - n;
        ListNode *cur = head, *pre;

        if(rem == 0) return cur->next;

        while(rem) {
            pre = cur;
            cur = cur->next;
            rem--;
        }

        pre->next = cur->next;

        return head;
    }
};
