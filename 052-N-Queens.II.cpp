class Solution {
public:
    int totalNQueens(int n) {
        //vector<bool> c1(n, false); // -
        vector<bool> c2(n, false); // |
        vector<bool> c3(2*n-1, false); // '\'
        vector<bool> c4(2*n-1, false); // /

        int result = 0;
        vector<string> current(n, string(n, '.'));

        doSolve(0, n, current, result, c2, c3, c4);
        return result;
    }
    void doSolve(int pos, int n, vector<string> &current, int &result, vector<bool> &c2, vector<bool> &c3, vector<bool> &c4) {
        if (pos == n) {
            result++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!c2[i] && !c3[i-pos+n-1] && !c4[i+pos]) {
                current[pos][i] = 'Q';
                c2[i] = true, c3[i-pos+n-1] = true, c4[i+pos] = true;
                doSolve(pos+1, n, current, result, c2, c3, c4);
                c2[i] = false, c3[i-pos+n-1] = false, c4[i+pos] = false;
                current[pos][i] = '.';
            }
        }
    }
};