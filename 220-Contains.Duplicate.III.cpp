class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() <= 1 || k < 0 || t < 0)
            return false;
        set<int> k_win;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k)
                k_win.erase(nums[i-k-1]);
                auto it = k_win.lower_bound(nums[i] - t);
                if (it != k_win.end() && (*it <= (long long)nums[i] + t))
                    return true;
                k_win.insert(nums[i]);
        }
        return false;
    }
};