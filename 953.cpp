// Date: 01/14/2020

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        unordered_map<char, int> dict;

        for(int i = 0; i < order.size(); i++) {
            dict[order[i]] = 'a' +  i;
        }

        for(auto& w : words) {
            for(int j = 0; j < w.size(); j++) {
                w[j] = dict[w[j]];
            }
        }

        auto orgArr = words;
        sort(words.begin(), words.end());

        return orgArr == words;
    }
};
