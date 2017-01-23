class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        for (int i = 0; i < 31; i++) {
            int mask = 1 << i;
            int p = 0, q = 0;
            for (int j = 0; j < n; j++)
                if (nums[j] & mask)
                    p++;
                else
                    q++;
            r += p * q;
        }
        return r;
    }
};