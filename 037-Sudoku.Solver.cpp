class Solution {
private:
    bool doSolve(vector<vector<char>> &board, int i, int j) {
        if (j == 9) return doSolve(board, i + 1, 0);
        if (i == 9) return true;
        if (board[i][j] == '.') {
            for (int k = 0; k < 9; k++) {
                board[i][j] = (char)(k + '1');
                if (isValid(board, i, j)) {
                    if (doSolve(board, i, j+1))
                        return true;
                }
                board[i][j] = '.';
            }
            return false;
        }
        else
            return doSolve(board, i, j+1);
    }
    bool isValid(vector<vector<char>> &board, int i, int j) {
        for (int k = 0; k < 9; k++)
            if (k != j && board[i][k] == board[i][j])
            return false;
        for (int k = 0; k < 9; k++)
            if (k != i && board[k][j] == board[i][j])
            return false;
        for (int r = i/3*3; r < i/3*3+3; r++)
            for (int c = j/3*3; c < j/3*3+3; c++)
                if ((r != i || c != j) && board[r][c] == board[i][j])
                return false;
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        doSolve(board, 0, 0);
    }
};