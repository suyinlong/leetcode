class Solution {
private:
    void sort(vector<int> &nums, int s, int e, int d) {
        if (d < 0 || s == e)
            return;
        int i = s;
        for (int j = s; j < e; j++)
            if (nums[j] & (1 << d))
                swap(nums[i++], nums[j]);
        sort(nums, s, i, d - 1);
        sort(nums, i, e, d - 1);
    }
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        sort(nums, 0, nums.size(), 31);
        int maxGap = 0;
        for (int i = 1; i < nums.size(); i++)
            maxGap = max(maxGap, nums[i-1] - nums[i]);
        return maxGap;
    }
};