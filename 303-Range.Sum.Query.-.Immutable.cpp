class NumArray {
private:
    vector<int> dp;
public:
    NumArray(vector<int> &nums) {
        dp.resize(nums.size(), 0);
        int t = 0;
        for (int i = 0; i < nums.size(); i++) {
            t += nums[i];
            dp[i] = t;
        }
    }

    int sumRange(int i, int j) {
        return dp[j] - (i > 0 ? dp[i-1] : 0);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);