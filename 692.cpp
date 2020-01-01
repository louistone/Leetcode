// Author: Tong Xu
// Date: 12/31/2019

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> wordMap;
        map<int, set<string>> freMap;
        vector<string> res;
        int count = k; // value k is changed, cause the bug, make it const to reduce the possibility of bugs

        for(auto& w : words) {
            wordMap[w]++;
        }

        for(auto& m : wordMap) {
            freMap[m.second].insert(m.first);
        }

        for(auto it = freMap.rbegin(); it != freMap.rend() && k > 0; it++) {
            auto& wordSet = it->second;
            for(auto& w : wordSet)
                res.push_back(w);
            k -= it->second.size();
        }

        while(res.size() != count) res.pop_back(); // break condition is == 

        return res;
    }
};
