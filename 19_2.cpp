// Author: Tong Xu
// Date: 1/3/2020
// 1 pass solution + fast/slow pointer

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *slow = dummy, *fast = dummy;
        int i = 0;

        while(i < n) {
            fast = fast->next;
            i++;
        }

        while(fast->next != NULL) { // this line of code is a little tricky
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
