class WordDictionary {
    class TrieNode {
    public:
        TrieNode() {
        }
        TrieNode *children[26] = {};
        bool isWord = false;
    };
private:
    TrieNode *root;
    bool search(TrieNode *node, string word) {
        if (word.length() == 0)
            return node->isWord;
        char c = word[0];
        if (c == '.') {
            for (int i = 0; i < 26; i++)
                if (node->children[i] && search(node->children[i], word.substr(1)))
                    return true;
            return false;
        }
        else {
            int idx = c - 'a';
            if (node->children[idx] == NULL)
                return false;
            return search(node->children[idx], word.substr(1));
        }
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *t = root;
        for (char c: word) {
            int idx = c - 'a';
            if (t->children[idx] == NULL)
                t->children[idx] = new TrieNode();
            t = t->children[idx];
        }
        t->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(root, word);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");