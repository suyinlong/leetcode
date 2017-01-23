class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool result = m.find(val) == m.end();

        m[val].push_back(nums.size());
        nums.emplace_back(val, m[val].size() - 1);

        return result;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool result = m.find(val) != m.end();

        if (result) {
            pair<int, int> last = nums.back();
            m[last.first][last.second] = m[val].back();
            nums[m[val].back()] = last;
            nums.pop_back();
            m[val].pop_back();
            if (m[val].size() == 0)
                m.erase(val);
        }

        return result;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        if (nums.size() == 0)
            return -1;
        return nums[rand() % nums.size()].first;
    }

private:
    unordered_map<int, vector<int>> m;
    vector<pair<int, int>> nums;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */