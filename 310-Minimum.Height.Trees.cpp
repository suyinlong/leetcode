class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 0)
            return vector<int>();
        if (n == 1)
            return vector<int>(1, 0);

        vector<vector<int>> edge(n, vector<int>());
        vector<int> degree(n, 0);
        for (auto p: edges) {
            edge[p.first].push_back(p.second);
            edge[p.second].push_back(p.first);
            degree[p.first]++;
            degree[p.second]++;
        }

        vector<int> ans;

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (degree[i] == 1)
                q.push(i);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int c = q.front();
                q.pop();
                degree[c]--;

                if (n <= 2)
                    ans.push_back(c);

                for (int p: edge[c]) {
                    degree[p]--;
                    if (degree[p] == 1)
                        q.push(p);
                }
            }
            n -= size;
        }

        return ans;

    }
};