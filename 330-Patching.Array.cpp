class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long max = 0, count = 0;
        for (long long i = 0; max < n;) {
            if (i >= nums.size() || max < nums[i] - 1) {
                max += max + 1;
                count++;
            }
            else {
                max += nums[i];
                i++;
            }
        }
        return count;
    }
};