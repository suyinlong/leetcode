class Solution {
public:
    static bool cmp(const pair<int, int>& i, const pair<int, int>& j) {
        if (i.first == j.first)
            return i.second > j.second;
        return i.first < j.first;
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> dp;
        for (int i = 0; i < envelopes.size(); i++) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
            if (it == dp.end())
                dp.push_back(envelopes[i].second);
            else
                *it = envelopes[i].second;
        }

        return dp.size();
    }
};