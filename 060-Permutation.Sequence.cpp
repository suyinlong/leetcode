class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
        vector<bool> used(10, false);
        string result = "";

        int p = k - 1;
        while (result.size() != n) {
            int d = p / fact[n - 1 - result.size()];
            p = p % fact[n - 1 - result.size()];
            //find (d+1)th number
            int i, j = -1;
            for (i = 1; i <= n; i++) {
                if (!used[i]) j++;
                if (j == d) {
                    used[i] = true;
                    break;
                }
            }
            result += to_string(i);

        }
        return result;

    }
};