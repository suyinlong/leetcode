class Solution {
public:
    bool dfs(vector<vector<char>> &board, string &word, int p, int i, int j) {
        if (board[i][j] == word[p]) {
            if (p == word.length() - 1)
                return true;
            board[i][j] = 0;
            if (i > 0 && dfs(board, word, p+1, i-1, j))
                return true;
            if (i < board.size()-1 && dfs(board, word, p+1, i+1, j))
                return true;
            if (j > 0 && dfs(board, word, p+1, i, j-1))
                return true;
            if (j < board[0].size()-1 && dfs(board, word, p+1, i, j+1))
                return true;
            board[i][j] = word[p];
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (word.length() == 0)
            return true;
        if (board.size() == 0)
            return false;
        if (board[0].size() == 0)
            return false;

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (dfs(board, word, 0, i, j))
                    return true;

        return false;
    }
};