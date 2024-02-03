class TrieNode {
public:
    TrieNode *word[26]; 
    bool is_last_word;
    TrieNode() {
        is_last_word = false;
        for (auto &x : word) x = nullptr;
    }
};

class Trie {
    TrieNode *root;
public:

    Trie() {
       root = new TrieNode();
    }
    
    void insert(string prefix) {
        TrieNode *p = root;
        for (int i = 0; i< prefix.size(); i++) {
            
            if (!p->word[prefix[i] - 'a']) {
                p->word[prefix[i] - 'a'] = new TrieNode();
            }
            p = p->word[prefix[i] - 'a'];
        }
        p->is_last_word = true;
    }

    bool search(string prefix, bool last_word) {
        TrieNode *p = root;
        for (int i = 0; i< prefix.size(); i++) {
            if (!p->word[prefix[i] - 'a']) return false;
            p = p->word[prefix[i]- 'a'];
        }

        if (last_word && !p->is_last_word) {
            return false;
        }
        return true;
    }
    
    bool search(string word) {
        return search(word, true);
    }
    
    bool startsWith(string prefix) {
        return search(prefix, false);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */