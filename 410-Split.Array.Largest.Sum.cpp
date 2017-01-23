class Solution {
private:
    bool solve(vector<int> &nums, int c, long long mid) {
        long long cur = 0;
        for (int k: nums) {
            if (k + cur <= mid) cur += k;
            else {
                c--;
                cur = k;
                if (c < 0) return false;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = INT_MIN, right = 0;
        for (int k: nums) {
            left = max(left, (long long)k);
            right += k;
        }

        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (solve(nums, m - 1, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};