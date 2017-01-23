class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i-1] + nums[i-1];
        return countAndSort(prefix, 1, n, lower, upper);
    }
private:
    int countAndSort(vector<long long> &prefix, int begin, int end, int lower, int upper) {
        if (begin == end)
            return (lower <= prefix[begin]) && (prefix[begin] <= upper);
        int mid = begin + (end - begin) / 2;
        int count = countAndSort(prefix, begin, mid, lower, upper) + countAndSort(prefix, mid + 1, end, lower, upper);
        int j = mid + 1, k = mid + 1;
        for (int i = begin; i <= mid; i++) {
            while (j <= end && prefix[j] < prefix[i] + lower) j++;
            while (k <= end && prefix[k] <= prefix[i] + upper) k++;
            count += k - j;
        }
        inplace_merge(prefix.begin() + begin, prefix.begin() + mid + 1, prefix.begin() + end + 1);
        return count;
    }
};