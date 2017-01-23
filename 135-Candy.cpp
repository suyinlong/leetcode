class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> nums(ratings.size(), 1);

        for (int i = 1; i < nums.size(); i++)
            if (ratings[i] > ratings[i-1])
                nums[i] = nums[i-1] + 1;
        for (int j = nums.size() - 2; j >= 0; j--)
            if (ratings[j] > ratings[j+1] && nums[j] <= nums[j+1])
                nums[j] = nums[j+1] + 1;
        int sum = 0;
        for (int c: nums)
            sum += c;
        return sum;
    }
};