class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> skyline;
        int n = buildings.size(), i = 0, X = 0, H = -1;
        priority_queue<pair<int, int>> pq;
        while (i < n || !pq.empty()) {
            if (pq.empty() || (i < n && buildings[i][0] <= pq.top().second)) {
                X = buildings[i][0];
                while (i < n && buildings[i][0] == X) {
                    pq.push(make_pair(buildings[i][2], buildings[i][1]));
                    i++;
                }
            }
            else {
                X = pq.top().second;
                while (!pq.empty() && pq.top().second <= X)
                    pq.pop();
            }
            H = pq.empty() ? 0 : pq.top().first;
            if (skyline.empty() || skyline.back().second != H)
                skyline.push_back(make_pair(X, H));
        }
        return skyline;
    }
};