class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int, int> m;
        for (char c: s)
            m[c]++;

        priority_queue<pair<int, int>> pq;
        for (auto it: m)
            pq.push(make_pair(it.second, it.first));

        string result;
        while (!pq.empty()) {
            auto p = pq.top();
            for (int i = 0; i < p.first; i++)
                result += p.second;
            pq.pop();
        }
        return result;
    }
};