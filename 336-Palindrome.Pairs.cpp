class Solution {

struct TrieNode {
    TrieNode *child[26] = {};
    int id = -1;
    vector<int> list;
};

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
            addWord(root, words[i], i);
        for (int i = 0; i < words.size(); i++)
            search(root, words[i], i, res);
        return res;
    }


private:
    void addWord(TrieNode *root, string &word, int id) {
        for (int i = word.size() - 1; i >= 0; i--) {
            int idx = word[i] - 'a';
            if (root->child[idx] == NULL)
                root->child[idx] = new TrieNode();
            if (isPalindrome(word, 0, i))
                root->list.push_back(id);
            root = root->child[idx];
        }
        root->list.push_back(id);
        root->id = id;
    }

    bool isPalindrome(string &word, int i, int j) {
        while (i < j)
            if (word[i++] != word[j--]) return false;
        return true;
    }

    void search(TrieNode *root, string &word, int id, vector<vector<int>> &res) {
        for (int i = 0; i < word.size(); i++) {
            if (root->id >= 0 && root->id != id && isPalindrome(word, i, word.size() - 1)) {
                vector<int> pPair = {id, root->id};
                res.push_back(pPair);
            }
            root = root->child[word[i] - 'a'];
            if (!root) return;
        }
        for (int j: root->list) {
            if (id == j) continue;
            vector<int> pPair = {id, j};
            res.push_back(pPair);
        }
    }
};