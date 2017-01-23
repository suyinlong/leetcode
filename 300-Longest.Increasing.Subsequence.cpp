class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> r;
        for (int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(r.begin(), r.end(), nums[i]);
            if (it == r.end())
                r.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return r.size();
    }
};