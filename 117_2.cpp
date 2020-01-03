// Author: Tong Xu
// Date: 1/2/2020
// dfs + dummy node solution
// cur = cur->next in for loop

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* dummy = new Node(0, NULL, NULL, NULL);
        Node* cur = root;
        for(Node* pre = dummy; cur; cur = cur->next) {
            if(cur->left) {
                pre->next = cur->left;
                pre = pre->next;
            }
            if(cur->right) {
                pre->next = cur->right;
                pre = pre->next;
            }
        }
        connect(dummy->next);
        dummy->next = NULL;
        delete dummy;
        return root;
    }
};
