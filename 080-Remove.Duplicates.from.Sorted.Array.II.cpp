class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int i = 0, j = 0;
        while (j < n) {
            if (i <= 1 || (nums[i-1] == nums[j] && nums[i-2] != nums[j]) || nums[i-1] != nums[j]) {
                nums[i++] = nums[j];
            }
            j++;
        }
        return i;
    }
};