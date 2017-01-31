class Solution {
    struct TrieNode {
        vector<int> idx;
        bool isWord = false;
        TrieNode *child[26]{};
    };
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int L = words[0].size();
        TrieNode *root = buildTrie(words);
        vector<vector<string>> res;
        vector<string> square(L, string(L, ' '));
        dfs(0, L, square, res, words, root);
        return res;

    }
private:
    TrieNode *buildTrie(vector<string> &words) {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            TrieNode *node = root;
            node->idx.push_back(i);
            for (int j = 0; j < words[i].size(); j++) {
                if (node->child[words[i][j] - 'a'] == NULL)
                    node->child[words[i][j] - 'a'] = new TrieNode();
                node = node->child[words[i][j] - 'a'];
                node->idx.push_back(i);
            }
            node->isWord = true;
        }
        return root;
    }
    void dfs(int k, int L, vector<string> &square, vector<vector<string>> &res, vector<string> &words, TrieNode *root) {
        if (k == L) {
            res.push_back(square);
            return;
        }
        TrieNode *node = root;
        for (int i = 0; i < k; i++) {
            node = node->child[square[k][i] - 'a'];
            if (!node) return;
        }
        for (int j: node->idx) {
            for (int i = k; i < L; i++)
                square[k][i] = square[i][k] = words[j][i];
            dfs(k + 1, L, square, res, words, root);
            for (int i = k; i < L; i++)
                square[k][i] = square[i][k] = ' ';
        }
    }
};