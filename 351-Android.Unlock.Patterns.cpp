class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> cross(10, vector<int>(10, 0));
        cross[1][3] = cross[3][1] = 2;
        cross[1][7] = cross[7][1] = 4;
        cross[3][9] = cross[9][3] = 6;
        cross[7][9] = cross[9][7] = 8;
        cross[1][9] = cross[9][1] = cross[2][8] = cross[8][2] = cross[3][7] = cross[7][3] = cross[4][6] = cross[6][4] = 5;
        vector<bool> used(10, false);
        int result = 0;
        doSearch(1, m, n, 1, used, cross, result);
        doSearch(1, m, n, 2, used, cross, result);
        result *= 4;
        doSearch(1, m, n, 5, used, cross, result);
        return result;
    }
    void doSearch(int step, int m, int n, int cur, vector<bool> &used, vector<vector<int>> &cross, int &result) {
        if (step >= m && step <= n)
            result += 1;
        if (step == n)
            return;
        used[cur] = true;
        for (int i = 1; i <= 9; i++) {
            if (!used[i] && (cross[cur][i] == 0 || used[cross[cur][i]]))
                doSearch(step + 1, m, n, i, used, cross, result);
        }
        used[cur] = false;
    }
};