class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0)
            return 0;
        int a = 0, b = 0, c = 0, x, y, z;
        for (int i = 0; i < n; i++) {
            x = min(b, c) + costs[i][0];
            y = min(a, c) + costs[i][1];
            z = min(a, b) + costs[i][2];
            a = x;
            b = y;
            c = z;
        }
        return min(a, min(b, c));
    }
};