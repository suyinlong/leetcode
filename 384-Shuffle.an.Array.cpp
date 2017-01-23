class Solution {
private:
    vector<int> orig, shuf;

public:
    Solution(vector<int> nums) {
        srand(time(NULL));
        orig = nums;
        shuf = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        shuf = orig;
        return shuf;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = shuf.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(shuf[i], shuf[j]);
        }
        return shuf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */