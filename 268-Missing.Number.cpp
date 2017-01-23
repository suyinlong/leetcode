class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i && nums[i] < nums.size())
                swap(nums[i], nums[nums[i]]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i)
                return i;
        }
        return nums.size();
    }
};