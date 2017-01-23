class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        if (nums1.empty() || nums2.empty()) return result;
        auto comp = [&nums1, &nums2](pair<int, int> &a, pair<int, int> &b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        for (int i = 0; i < min(k, (int)nums1.size()); i++)
            pq.push(make_pair(i, 0));
        for (int i = 0; i < k; i++) {
            if (pq.empty()) break;
            int a = pq.top().first, b = pq.top().second;
            pq.pop();
            result.push_back(make_pair(nums1[a], nums2[b]));
            if (b < nums2.size() - 1)
                pq.push(make_pair(a, b + 1));
        }
        return result;
    }
};