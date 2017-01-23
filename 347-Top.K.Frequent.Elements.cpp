class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int c: nums)
            map[c]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (auto i: map) {
            q.push({i.second, i.first});
            if (q.size() == k + 1)
                q.pop();
        }
        vector<int> r;
        while (!q.empty()) {
            r.push_back(q.top().second);
            q.pop();
        }
        return r;
    }
};