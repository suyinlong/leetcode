class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, int> nodeIdxMap;
        vector<vector<pair<int, double>>> edges;
        vector<double> ans;

        for (int i = 0; i < equations.size(); i++) {
            string sStart = equations[i].first, sEnd = equations[i].second;
            int iStart, iEnd;
            if (nodeIdxMap.find(sStart) == nodeIdxMap.end()) {
                nodeIdxMap[sStart] = edges.size();
                edges.push_back(vector<pair<int, double>>());
            }
            iStart = nodeIdxMap.find(sStart)->second;
            if (nodeIdxMap.find(sEnd) == nodeIdxMap.end()) {
                nodeIdxMap[sEnd] = edges.size();
                edges.push_back(vector<pair<int, double>>());
            }
            iEnd = nodeIdxMap.find(sEnd)->second;
            edges[iStart].push_back(make_pair(iEnd, values[i]));
            edges[iEnd].push_back(make_pair(iStart, 1 / values[i]));
        }

        for (int i = 0; i < queries.size(); i++) {
            string qStart = queries[i].first, qEnd = queries[i].second;
            if (nodeIdxMap.find(qStart) == nodeIdxMap.end() || nodeIdxMap.find(qEnd) == nodeIdxMap.end()) {
                ans.push_back(-1.0);
                continue;
            }
            int start = nodeIdxMap.find(qStart)->second, end = nodeIdxMap.find(qEnd)->second;
            if (start == end) {
                ans.push_back(1.0);
                continue;
            }

            queue<pair<int, double>> bfs;
            vector<bool> visited(edges.size(), false);

            bfs.push(make_pair(start, 1.0));
            visited[start] = true;

            int u = start; double m = 1.0;
            while (!bfs.empty()) {
                u = bfs.front().first;
                m = bfs.front().second;
                bfs.pop();
                if (u == end)
                    break;
                for (int i = 0; i < edges[u].size(); i++) {
                    int v = edges[u][i].first;
                    double w = edges[u][i].second;
                    if (!visited[v]) {
                        visited[v] = true;
                        bfs.push(make_pair(v, m * w));
                    }
                }
            }
            if (u == end)
                ans.push_back(m);
            else
                ans.push_back(-1.0);
        }

        return ans;
    }
};