class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, k = 0;
        while (k <= j) {
            if (nums[k] == 0) {
                if (k > i) swap(nums[k], nums[i]);
                else k++;
                i++;
            }
            else if (nums[k] == 2) {
                if (k < j) swap(nums[k], nums[j]);
                else k++;
                j--;
            }
            else k++;

        }

    }
};