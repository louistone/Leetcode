// Author: Tong Xu
// Date: 12/30/2019

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        // build graph
        unordered_map<int, unordered_set<int>> outGraph;
        unordered_map<int, unordered_set<int>> inGraph;
        for(auto& p : pre) {
            outGraph[p[1]].insert(p[0]);
            inGraph[p[0]].insert(p[1]);
        }

        // queue
        queue<int> courseQueue;
        for(int i = 0; i < numCourses; i++) {
            if(!inGraph.count(i))
                courseQueue.push(i);
        }

        // perform bfs
        int count = courseQueue.size();
        while(!courseQueue.empty()) {
            auto cur = courseQueue.front();
            courseQueue.pop();

            for(auto& nei : outGraph[cur]) {
                inGraph[nei].erase(cur);
                if(inGraph[nei].empty()) {
                    courseQueue.push(nei);
                    count++;
                }
            }
        }

        return count == numCourses;
    }
};
