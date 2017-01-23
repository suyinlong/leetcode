class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int l = 0, r = nums.size()-1;
        while (l != r) {
            if (l == r)
                return l;
            else {
                int mid = l + ((r - l) >> 1);
                if (nums[mid] < nums[mid+1])
                    l = mid + 1;
                else
                    r = mid;
            }
        }
        return l;
    }
};