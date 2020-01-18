// Date: 1/18/2020

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // count
        unordered_map<char, int> map;
        for(const auto& t : tasks) map[t]++;

        // priority_queue
        priority_queue<pair<int, char>> pq;
        for(auto& m : map) {
            pq.push({m.second, m.first});
        }

        // cycle concept
        int cycle = n + 1, alltime = 0;

        while(!pq.empty()) {
            int time = 0;
            vector<pair<int, char>> tmp;
            for(int i = 0; i < cycle; i++) {
                if(!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }

            for(auto& t : tmp) {
                if(--t.first > 0) {
                    pq.push(t);
                }
            }

            alltime += pq.empty() ? time : cycle;
        }

        return alltime;
    }
};
