class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();
        int i = 0, j = 0, k = nums[0];
        while (j < nums.size()) {
            while (j < nums.size() && nums[j] == k)
                j++;
            nums[i++] = k;
            if (j < nums.size())
                k = nums[j];
        }
        return i;
    }
};