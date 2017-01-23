class Solution {
    struct cmp {
        bool operator()(pair<int, int> &a, pair<int, int> &b) {
            return a.first < b.first;
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.size() < k || k == 0)
            return ans;

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (int i = 0; i < k; i++)
            pq.push(make_pair(nums[i], i));
        ans.push_back(pq.top().first);

        for (int i = k; i < nums.size(); i++) {
            while (!pq.empty() && pq.top().second <= i - k)
                pq.pop();
            pq.push(make_pair(nums[i], i));
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};