class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {

    }
    TrieNode *children[26] = {};
    bool isWord = false;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *t = root;
        for (char c: word) {
            int idx = c - 'a';
            if (t->children[idx] == NULL)
                t->children[idx] = new TrieNode();
            t = t->children[idx];
        }
        t->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *t = root;
        for (char c: word) {
            int idx = c - 'a';
            if (t->children[idx] == NULL)
                return false;
            t = t->children[idx];
        }
        return t->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *t = root;
        for (char c: prefix) {
            int idx = c - 'a';
            if (t->children[idx] == NULL)
                return false;
            t = t->children[idx];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");