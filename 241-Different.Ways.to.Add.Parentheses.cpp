class Solution {
public:
    vector<int> doCompute(string &s, int l, int r) {
        vector<int> result;
        vector<int> symbol;
        for (int i = l; i <= r; i++)
            if (s[i] == '+' || s[i] == '-' || s[i] == '*')
                symbol.push_back(i);
        if (symbol.size() == 0) {
            result.push_back(stoi(s.substr(l, r - l + 1)));
            return result;
        }
        for (int i = 0; i < symbol.size(); i++) {
            vector<int> a = doCompute(s, l, symbol[i] - 1), b = doCompute(s, symbol[i] + 1, r);
            for (int aa: a)
                for (int bb: b) {
                    if (s[symbol[i]] == '+')
                        result.push_back(aa + bb);
                    else if (s[symbol[i]] == '-')
                        result.push_back(aa - bb);
                    else
                        result.push_back(aa * bb);
                }
        }
        return result;
    }
    vector<int> diffWaysToCompute(string input) {
        return doCompute(input, 0, input.length() - 1);
    }
};