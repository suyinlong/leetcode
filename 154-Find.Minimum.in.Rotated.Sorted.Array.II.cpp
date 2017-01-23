class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int left = 0, right = nums.size() - 1, mid;
        while (right - left > 1) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] == nums[left])
                left++;
            else if (nums[mid] == nums[right])
                right--;
            else if (nums[mid] > nums[right])
                left = mid;
            else
                right = mid;
        }
        return min(nums[left], nums[right]);
    }
};