class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        if (n == 0) return false;

        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++)
            pos[org[i]] = i;

        vector<bool> flag(n + 1, false);
        bool check = false;
        int cnt = n - 1;
        for (auto seq: seqs) {
            for (int i = 0; i < seq.size(); i++) {
                check = true;
                if (seq[i] <= 0 || seq[i] > n) return false;
                if (i == 0) continue;
                int x = pos[seq[i-1]], y = pos[seq[i]];
                if (x >= y) return false;
                if (!flag[x] && x + 1 == y) {
                    flag[x] = true;
                    cnt--;
                }
            }
        }
        return (check && (cnt == 0));
    }
};