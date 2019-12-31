/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* copy = new Node(node->val, {});
        unordered_map<Node*, Node*> nodeMap;

        nodeMap[node] = copy;
        queue<Node*> nodeQueue;
        nodeQueue.push(node);

        while(!nodeQueue.empty()) {
            auto cur = nodeQueue.front();
            nodeQueue.pop();

            for(auto& c : cur->neighbors) {
                if(!nodeMap.count(c)) {
                    Node* copyC = new Node(c->val, {});
                    nodeMap[c] = copyC;
                    nodeQueue.push(c); // this line of code should be inside the if statement, else time limit exceeded, using hashtable as visited array
                }
                nodeMap[cur]->neighbors.push_back(nodeMap[c]);
            }
        }

        return copy;
    }
};
