class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]], prev;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    /*
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1;

        while (l < r) {
            int m = l + ((r - l) >> 1);
            int cnt = 0;
            for (int i = 0; i < n; i++)
                if (nums[i] <= m)
                    cnt++;
            if (cnt <= m) l = m + 1;
            else r = m;
        }
        return l;
    }
    */
};