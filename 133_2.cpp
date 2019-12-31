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
        dfs(node);
        return nodeMap[node];
    }

private:
    unordered_map<Node*, Node*> nodeMap;

    Node* dfs(Node* node) {

        if(!node) return NULL;

        if(nodeMap.count(node)) {
            return nodeMap[node];
        }


        Node* copy = new Node(node->val, {});
        nodeMap[node] = copy;

        for(auto& c : node->neighbors) {
            nodeMap[node]->neighbors.push_back(dfs(c));
        }

        return copy;
    }
};
