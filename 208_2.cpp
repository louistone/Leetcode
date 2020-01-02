struct TrieNode {
    char cur;
    bool isWord;
    unordered_map<char, TrieNode*> nodeMap;
    
    TrieNode() {
        isWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

    TrieNode* traverse(string& word) {
        TrieNode* cur = root;
        for(const auto& c : word) {
            if(!cur->nodeMap.count(c)) return NULL;
            cur = cur->nodeMap[c];
        }
        return cur;
    }
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for(const auto& c : word) {
            if(!(cur->nodeMap).count(c)) {
                cur->nodeMap[c] = new TrieNode();
                
            }
            cur = cur->nodeMap[c];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* end = traverse(word);
        return end && end->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* end = traverse(prefix);
        return end;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */