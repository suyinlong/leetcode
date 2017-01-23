class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int n = str.size();
        if (n <= 1) return false;
        for (int i = 1; i <= n / 2; i++)
            if (n % i == 0) {
                string leftShift = str.substr(i);
                leftShift += str.substr(0, i);
                if (leftShift == str) return true;
            }
        return false;
    }
};