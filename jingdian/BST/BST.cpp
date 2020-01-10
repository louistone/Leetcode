#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;

  Node(int value) {
    val = value;
    left = NULL;
    right = NULL;
  }
};

class BST {
private:
  Node* root;

  Node* findHelper(Node* cur, int val) {
    if(!cur) return NULL;
    if(cur->val == val) return cur;
    if(val < cur->val) return findHelper(cur->left, val);
    return findHelper(cur->right, val);
  }

  Node* insertHelper(Node* cur, int val) {
    if(!cur) {
      //cur = new Node(val);
      //return cur;
      return new Node(val); // this line of code caused bug
    }

    if(val >= cur->val) {
      // if(!cur->right) {
      //   cur->right = new Node(cur->val);
      //   return;
      // }
      cur->right = insertHelper(cur->right, val);
    }
    else {
      cur->left = insertHelper(cur->left, val);
    }

    return cur; // this line of code caused bug
    //return NULL;
  }

  void printHelper(Node* cur) {
    if(!cur) return;
    printHelper(cur->left);
    cout << cur->val << endl;
    printHelper(cur->right);
  }

public:
  BST() {

  }

  BST(int val) {
    root = new Node(val);
  }

  Node* find(int val) {
    return findHelper(root, val);
  }

  void insert(int val) {
    insertHelper(root, val);
  }

  void print() {
    printHelper(root);
  }
};

int main() {
  BST* tree = new BST(3);
  vector<int> arr {9, 2, 0, 3, 1, 7};
  //vector<int> arr {9, 2, 3};

  for(const auto& i : arr) {
    tree->insert(i);
  }

  tree->print();

  return 0;
}
