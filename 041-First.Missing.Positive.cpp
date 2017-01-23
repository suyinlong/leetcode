class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0)
            return 1;
        for (int i = 0; i < nums.size(); i++) {
            int j = nums[i];
            if (j > 0 && j <= nums.size() && i != (j-1) && nums[j-1] != nums[i]) {
                nums[j-1] = nums[j-1] ^ nums[i];
                nums[i] = nums[j-1] ^ nums[i];
                nums[j-1] = nums[j-1] ^ nums[i];
                i--;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }
};