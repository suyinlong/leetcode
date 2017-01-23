class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int l;
        for (l = nums.size() - 1; l > 0; l--)
            if (nums[l] > nums[l-1])
                break;
        if (l == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int r;
        for (r = nums.size() - 1; r > 0; r--)
            if (nums[r] > nums[l-1])
                break;
        swap(nums[l-1], nums[r]);
        sort(nums.begin() + l, nums.end());
    }
};