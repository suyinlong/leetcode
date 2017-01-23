class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int lp = 1, rp = 1;
        for (int i = 0; i < nums.size(); i++) {
            result[i] *= lp;
            result[nums.size() - i - 1] *= rp;
            lp *= nums[i];
            rp *= nums[nums.size() - i - 1];
        }
        return result;
    }
};