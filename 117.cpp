//Author: Tong Xu
//Date: 1/2/2020

// Levelorder traversal bfs solution

class Solution {
public:
    Node* connect(Node* root) {
      if(!root) return NULL;
      queue<Node*> nodeQueue;
      Node* cur;
      Node* copy = root;
      int size, i;
      nodeQueue.push(copy);

      while(!nodeQueue.empty()) {
        size = nodeQueue.size();

        for(i = 0; i < size; i++) {
          cur = nodeQueue.front();
          nodeQueue.pop();
          if(i < size-1) cur->next = nodeQueue.front();
          if(cur->left) nodeQueue.push(cur->left);
          if(cur->right) nodeQueue.push(cur->right);
        }
      }

      return root;
    }
};
