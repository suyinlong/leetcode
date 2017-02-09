class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> nextG;
        for (int n: nums) {
            if (s.empty() || s.top() > n)
                s.push(n);
            else {
                while (!s.empty() && s.top() < n) {
                    nextG[s.top()] = n;
                    s.pop();
                }
                s.push(n);
            }
        }
        vector<int> res;
        for (int f: findNums) {
            if (nextG.find(f) == nextG.end())
                res.push_back(-1);
            else
                res.push_back(nextG[f]);
        }
        return res;
    }
};