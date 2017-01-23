class NumArray {
private:
    vector<int> _nums;
    vector<int> BIT;
    int n;
public:
    NumArray(vector<int> &nums) {
        _nums = nums;
        n = nums.size();
        BIT.resize(n + 1);
        for (int i = 0; i <= n; i++)
            BIT[i] = 0;
        for (int i = 0; i < n; i++)
            _update(i, nums[i]);
    }
    void _update(int i, int val) {
        i++;
        while (i <= n) {
            BIT[i] += val;
            i += i & (-i);
        }
    }
    void update(int i, int val) {
        _update(i, val - _nums[i]);
        _nums[i] = val;
    }
    int _sumRange(int i) {
        i++;
        int sum = 0;
        while (i > 0) {
            sum += BIT[i];
            i -= i & (-i);
        }
        return sum;
    }
    int sumRange(int i, int j) {
        return _sumRange(j) - _sumRange(i) + _nums[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);