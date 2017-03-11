class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> map;
        for (int c: nums)
            map[c]++;
        int res = 0;
        for (auto it = map.begin(); it != map.end(); it++) {
            int a = it->first;
            if (k == 0) {
                if (it->second >= 2)
                    res += 1;
            }
            else {
                if (map.find(a + k) != map.end())
                    res += 1;
            }
        }
        return res;
    }
};