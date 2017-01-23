class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) return false;

        unordered_map<int, vector<int>> step;
        for (int i: stones)
            step[i] = vector<int>();
        step[1].push_back(0);

        for (int i: stones) {
            for (auto it = step[i].begin(); it != step[i].end(); it++) {
                int l = i - *it;
                for (int j = l - 1; j <= l + 1; j++) {
                    if (j > 0 && step.find(i + j) != step.end() && (step[i+j].size() == 0 || step[i+j].back() != i))
                        step[i+j].push_back(i);
                }
            }
        }
        return step[stones[n-1]].size() > 0;
    }
};