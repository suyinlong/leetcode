class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int t = 0;
        for (int k: nums)
            t ^= k;
        int mask = t & (~(t - 1)), g1 = 0, g2 = 0;
        for (int k: nums)
            if ((k & mask) == 0)
                g1 ^= k;
            else
                g2 ^= k;
        vector<int> ans = {g1, g2};
        return ans;
    }
};