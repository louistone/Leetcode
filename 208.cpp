// Author: Tong Xu
// Date: 1/1/2020
// This code use vector as children

struct TrieNode {
    bool isWord;
    vector<TrieNode*> children;
    
    TrieNode() {
        isWord = false;
        children.resize(26);
    }
};

class Trie {
private:
    TrieNode* root;

    TrieNode* traverse(string& word) {
        TrieNode* cur = root;
        for(const auto& c : word) {
            if(!cur->children[c-'a']) return NULL;
            cur = cur->children[c-'a'];
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
            if(!cur->children[c-'a']) {
                cur->children[c-'a'] = new TrieNode();
                
            }
            cur = cur->children[c-'a'];
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