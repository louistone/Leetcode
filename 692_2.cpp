// Author: Tong Xu
// Date: 12/31/2019

// This solution uses a priority_queue and customized comparator

struct comp {
    bool operator()(pair<string, int>& p1, pair<string, int>& p2) {
        return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordMap;
        vector<string> res;

        for(auto& w : words) wordMap[w]++;
        priority_queue<pair<string,int>, vector<pair<string, int>>, comp> wordPairQueue;
        for(auto& m : wordMap) {
            wordPairQueue.push(m);
            if(wordPairQueue.size() > k) wordPairQueue.pop();
        }

        while(!wordPairQueue.empty()) {
            res.insert(res.begin(), wordPairQueue.top().first);
            wordPairQueue.pop();
        }

        return res;
    }
};
