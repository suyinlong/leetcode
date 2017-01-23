class Solution {
private:
    vector<int> id;
    vector<int> count;
    unordered_map<int, int> map;

    int findRoot(int i) {
        if (i != id[i])
            id[i] = findRoot(id[i]);
        return id[i];
    }
    void unite(int num1, int num2) {
        int p = findRoot(map.find(num1)->second);
        int q = findRoot(map.find(num2)->second);
        if (p != q) {
            if (count[p] > count[q]) {
                id[q] = p;
                count[p] += count[q];
            }
            else {
                id[p] = q;
                count[q] += count[p];
            }
        }
    }
public:
    int longestConsecutive(vector<int>& nums) {
        id.resize(nums.size());
        count.resize(nums.size(), 0);
        map.clear();

        for (int i = 0; i < nums.size(); i++) {
            id[i] = i;
            count[i] = 1;
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = i;
                if (map.find(nums[i] - 1) != map.end())
                    unite(nums[i] - 1, nums[i]);
                if (map.find(nums[i] + 1) != map.end())
                    unite(nums[i] + 1, nums[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, count[i]);
        }
        return ans;
    }
};