class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size();

        while (i < j) {
            int mid = i + ((j - i) >> 1);
            if (nums[mid] >= target)
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }
};