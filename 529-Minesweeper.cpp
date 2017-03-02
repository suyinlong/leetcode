class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int h = board.size(), w = board[0].size();
        vector<vector<char>> cBoard = calcBoard(board);
        vector<vector<char>> res = board;

        int x = click[0], y = click[1];
        if (cBoard[x][y] == 'M' || cBoard[x][y] == 'X') {
            res[x][y] = 'X';
            return res;
        }
        queue<pair<int, int>> q;
        if (board[x][y] == 'E') {
            q.push(make_pair(x, y));
            board[x][y] = 'T';
        }

        while (!q.empty()) {
            int a = q.front().first, b = q.front().second;
            q.pop();
            if (res[a][b] != 'E') continue;
            res[a][b] = cBoard[a][b];
            if (res[a][b] != 'B') continue;
            for (int aa = -1; aa <= 1; aa++) {
                for (int bb = -1; bb <= 1; bb++) {
                    if ((aa == 0 && bb == 0) || a + aa < 0 || a + aa >= h || b + bb < 0 || b + bb >= w)
                        continue;
                    if (res[a+aa][b+bb] == 'E' && board[a+aa][b+bb] != 'T') {
                        q.push(make_pair(a+aa, b+bb));
                        board[a+aa][b+bb] = 'T';
                    }
                }
            }
        }

        return res;
    }
private:
    vector<vector<char>> calcBoard(vector<vector<char>> &board) {
        int h = board.size(), w = board[0].size();
        vector<vector<char>> cBoard = vector<vector<char>>(h, vector<char>(w, '.'));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] != 'E')
                    cBoard[i][j] = board[i][j];
                else {
                    int m = 0;
                    for (int ii = -1; ii <= 1; ii++) {
                        for (int jj = -1; jj <= 1; jj++) {
                            if ((ii == 0 && jj == 0) || i + ii < 0 || i + ii >= h || j + jj < 0 || j + jj >= w)
                                continue;
                            if (board[i+ii][j+jj] == 'M' || board[i+ii][j+jj] == 'X')
                                m++;
                        }
                    }
                    if (m == 0)
                        cBoard[i][j] = 'B';
                    else
                        cBoard[i][j] = '0' + m;
                }
            }
        }
        return cBoard;
    }
};