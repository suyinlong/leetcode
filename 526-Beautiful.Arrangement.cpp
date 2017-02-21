class Solution {
public:
    int countArrangement(int N) {
        vector<bool> used(N + 1, false);
        int res = 0;
        search(1, N, used, res);
        return res;
    }
    void search(int p, int N, vector<bool> &used, int &res) {
        if (p > N) {
            res++;
            return;
        }
        for (int i = p; i <= N; i += p)
            if (!used[i]) {
                used[i] = true;
                search(p + 1, N, used, res);
                used[i] = false;
            }
        for (int i = 1; i < p; i++)
            if (!used[i] && p % i == 0) {
                used[i] = true;
                search(p + 1, N, used, res);
                used[i] = false;
            }
    }
};