class TwoSum {
private:
    unordered_map<int, int> nums;
public:

    // Add the number to an internal data structure.
    void add(int number) {
        nums[number]++;
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for (auto it = nums.begin(); it != nums.end(); it++) {
            int a = it->first, b = value - a;
            if (a == b && it->second > 1)
                return true;
            if (a != b && nums.find(b) != nums.end())
                return true;
        }
        return false;
    }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);