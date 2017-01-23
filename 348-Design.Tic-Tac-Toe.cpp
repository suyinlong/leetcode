class TicTacToe {
private:
    int n;
    vector<int> grid;
    vector<int> rows;
    vector<int> cols;
    int diag, anti_diag;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        grid.resize(n * n, 0);
        rows.resize(n, 0);
        cols.resize(n, 0);
        diag = 0;
        anti_diag = 0;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int idx = row * n + col;
        grid[idx] = player;
        if (player == 1) {
            rows[row] ++;
            cols[col] ++;
            if (row == col) diag++;
            if (row + col == n - 1) anti_diag++;
            if (rows[row] == n || cols[col] == n || diag == n || anti_diag == n)
                return 1;
        }
        else {
            rows[row] --;
            cols[col] --;
            if (row == col) diag--;
            if (row + col == n - 1) anti_diag--;
            if (rows[row] == -n || cols[col] == -n || diag == -n || anti_diag == -n)
                return 2;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */