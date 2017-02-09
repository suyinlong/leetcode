class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<string> res(n);

        if (n == 0) return res;

        unordered_map<int, int> scoreToIdx;
        for (int i = 0; i < n; i++)
            scoreToIdx[nums[i]] = i;
        vector<int> sortScore(nums);
        sort(sortScore.begin(), sortScore.end());

        for (int i = n - 1; i >= 0; i--) {
            int score = sortScore[i];
            if (i == n - 1)
                res[scoreToIdx[score]] = "Gold Medal";
            else if (i == n - 2)
                res[scoreToIdx[score]] = "Silver Medal";
            else if (i == n - 3)
                res[scoreToIdx[score]] = "Bronze Medal";
            else
                res[scoreToIdx[score]] = to_string(n - i);
        }
        return res;
    }
};