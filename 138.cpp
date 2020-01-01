// Author: Tong Xu
// Date: 12/31/2019
// This solution use a hashtable and 2 pass
// Also assumes there's no cycle

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        unordered_map<Node*, Node*> nodeMap;

        Node* cur = head;
        Node* dummy = new Node(-1);
        Node* copy = dummy;

        while(cur) {
            copy->next = new Node(cur->val);
            nodeMap[cur] = copy->next;
            cur = cur->next;
            copy = copy->next;
        }

        copy = dummy->next, cur = head;
        while(cur) {
            copy->random = nodeMap[cur->random];
            copy = copy->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};
