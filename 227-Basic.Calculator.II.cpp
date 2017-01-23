class Solution {
public:
    int calculate(string s) {
        istringstream sin("+" + s + "+");
        long long result = 0, term = 0, n;
        char op;
        while (sin >> op) {
            if (op == '+' || op == '-') {
                result += term;
                sin >> term;
                term *= 44 - op;
            }
            else {
                sin >> n;
                if (op == '*')
                    term *= n;
                else
                    term /= n;
            }
        }
        return result;
    }
};