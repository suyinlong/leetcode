class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<bool> dup(9, false);
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.' && dup[c - '1'])
                    return false;
                if (c != '.')
                    dup[c - '1'] = true;
            }
        }
        for (int i = 0; i < 9; i++) {
            vector<bool> dup(9, false);
            for (int j = 0; j < 9; j++) {
                char c = board[j][i];
                if (c != '.' && dup[c - '1'])
                    return false;
                if (c != '.')
                    dup[c - '1'] = true;
            }
        }
        for (int i = 0; i < 9; i++) {
            vector<bool> dup(9, false);
            for (int j = 0; j < 9; j++) {
                int a = i / 3 * 3 + j / 3, b = i % 3 * 3 + j % 3;
                char c = board[a][b];
                if (c != '.' && dup[c - '1'])
                    return false;
                if (c != '.')
                    dup[c - '1'] = true;
            }
        }
        return true;
    }
};