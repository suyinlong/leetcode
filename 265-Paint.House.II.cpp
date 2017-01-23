class Solution {
    struct cmp {
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        }
    };
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0)
            return 0;
        int k = costs[0].size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pqOld, pqNew;
        for (int i = 0; i < k; i++) {
            pqOld.push(make_pair(0, i));
        }
        for (int i = 0; i < n; i++) {
            while (!pqNew.empty()) pqNew.pop();
            for (int j = 0; j < k; j++) {
                int localMin;
                auto p = pqOld.top();
                if (p.second != j)
                    localMin = p.first;
                else {
                    pqOld.pop();
                    localMin = pqOld.top().first;
                    pqOld.push(p);
                }
                pqNew.push(make_pair(localMin + costs[i][j], j));
            }
            pqOld = pqNew;
        }

        return pqOld.top().first;
    }
};