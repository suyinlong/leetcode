class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0 || board[0].size() == 0)
            return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int count = - (board[i][j] & 0x01);
                for (int I = max(0, i-1); I < min(m, i+2); I++)
                    for (int J = max(0, j-1); J < min(n, j+2); J++)
                        count += board[I][J] & 0x01;
                if ((count == 2 && board[i][j]) || count == 3)
                    board[i][j] |= 0x02;

            }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] >>= 1;
    }
};