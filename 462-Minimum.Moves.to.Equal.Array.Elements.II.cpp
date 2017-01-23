class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int mid = (nums.size() - 0) >> 1;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += abs(nums[i] - nums[mid]);
        }
        return ans;
    }
};