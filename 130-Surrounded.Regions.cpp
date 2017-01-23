class Solution {
public:
    void bfs(queue<pair<int, int>> &queue, vector<vector<char>> &board) {
        while (!queue.empty()) {
            pair<int, int> p = queue.front();
            queue.pop();
            int i = p.first, j = p.second;
            if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O')
                continue;
            board[i][j] = '#';
            queue.push(pair<int, int>(i-1, j));
            queue.push(pair<int, int>(i+1, j));
            queue.push(pair<int, int>(i, j-1));
            queue.push(pair<int, int>(i, j+1));
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0)
            return;

        queue<pair<int, int>> queue;
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O')
                queue.push(pair<int, int>(i, 0));
            if (board[i][board[0].size() - 1] == 'O')
                queue.push(pair<int, int>(i, board[0].size() - 1));
        }
        for (int j = 1; j < board[0].size() - 1; j++) {
            if (board[0][j] == 'O')
                queue.push(pair<int, int>(0, j));
            if (board[board.size() - 1][j] == 'O')
                queue.push(pair<int, int>(board.size() - 1, j));
        }
        bfs(queue, board);
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == '#')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
    }

};