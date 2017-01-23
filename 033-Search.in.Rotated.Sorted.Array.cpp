class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target)
                return mid;
            if (nums[left] <= nums[mid])
                if (target < nums[left] || target > nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            else
                if (target < nums[mid] || target > nums[right])
                    right = mid - 1;
                else
                    left = mid + 1;
        }
        return -1;
    }
};