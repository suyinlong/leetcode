class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> count(32, 0);
        for (int c: nums) {
            for (int i = 0; i < 32; i++)
                if (((c >> i) & 1) == 1)
                     count[i]++;
        }
        int ans = 0;
        for (int i = 0; i < 32; i++)
            ans += (count[i] % 3) * (1 << i);
        return ans;
    }
};