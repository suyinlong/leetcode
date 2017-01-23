class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0)
            return 0;

        int i = 0, j = nums.size() - 1;
        while (j >= 0 && nums[j] == val)
            j--;
        while (i < j) {
            if (nums[i] == val)
                swap(nums[i], nums[j]);
            while (j >= 0 && nums[j] == val)
                j--;
            i++;
        }
        return j+1;
    }
};