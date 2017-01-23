class Solution {
struct TrieNode {
    TrieNode *child[26]{};
    int idx = -1;
};
public:
    TrieNode *buildTrie(vector<string>& words) {
        TrieNode *root = new TrieNode;
        for (int i = 0; i < words.size(); i++) {
            TrieNode *p = root;
            for (auto c : words[i]) {
                auto j = c - 'a';
                if (!p->child[j])
                    p->child[j] = new TrieNode;
                p = p->child[j];
            }
            p->idx = i;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode *p, vector<int> &found_idx) {
        auto c = board[i][j];
        if (!c || !p->child[c - 'a'])
            return;
        p = p->child[c - 'a'];
        if (p->idx != -1) {
            found_idx.push_back(p->idx);
            p->idx = -1;
        }
        board[i][j] = 0;

        if (i > 0) dfs(board, i - 1, j, p, found_idx);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, found_idx);
        if (j > 0) dfs(board, i, j - 1, p, found_idx);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, found_idx);

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = buildTrie(words);
        vector<int> found_idx;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                dfs(board, i, j, root, found_idx);
        vector<string> found_words;
        for (int k : found_idx)
            found_words.push_back(words[k]);
        return found_words;
    }
};