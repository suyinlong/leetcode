class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mid = nums[n / 2];

        int i = 0, j = 0, k = n-1;
        while (j <= k) {
            if (nums[reIndex(j, n)] > mid)
                swap(nums[reIndex(i++, n)], nums[reIndex(j++, n)]);
            else if (nums[reIndex(j, n)] < mid)
                swap(nums[reIndex(j, n)], nums[reIndex(k--, n)]);
            else
                j++;
        }
    }
    int reIndex(int i, int n) {
        return (1+2*(i)) % (n|1);
    }
};