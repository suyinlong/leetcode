class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> diff(length, 0);
        for (vector<int> update: updates) {
            diff[update[0]] += update[2];
            if (update[1] < length - 1)
                diff[update[1] + 1] -= update[2];
        }
        int k = 0;
        for (int i = 0; i < length; i++) {
            int t = diff[i];
            diff[i] += k;
            k += t;
        }
        return diff;
    }
};