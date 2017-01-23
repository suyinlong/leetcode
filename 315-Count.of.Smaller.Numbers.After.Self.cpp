class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        vector<int> result(n);
        if (n == 0) return result;

        vector<int> rel(nums);
        sort(rel.begin(), rel.end());
        for (int i = 0; i < n; i++) {
            int k = lower_bound(rel.begin(), rel.end(), nums[i]) - rel.begin() + 1;
            nums[i] = k;
        }
        BIT.resize(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            result[i] = sum(nums[i] - 1);
            update(nums[i], 1);
        }


        return result;
    }
private:
    void update(int i, int val) {
        i++;
        while (i <= n) {
            BIT[i] += val;
            i += i & (-i);
        }
    }
    int sum(int i) {
        i++;
        int s = 0;
        while (i > 0) {
            s += BIT[i];
            i -= i & (-i);
        }
        return s;
    }
    int n;
    vector<int> BIT;
};