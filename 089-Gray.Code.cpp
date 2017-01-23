class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0)
            return vector<int>(1, 0);
        vector<int> t = grayCode(n - 1);
        int add = 1 << (n - 1);
        vector<int> result(t);
        for (int i = t.size() - 1; i >= 0; i--)
            result.push_back(t[i] + add);
        return result;
    }
};