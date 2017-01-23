class Solution {
public:
    bool isStrobogrammatic(string num) {
        string s = num;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0' || s[i] == '1' || s[i] =='8')
                continue;
            else if (s[i] == '6')
                s[i] = '9';
            else if (s[i] == '9')
                s[i] = '6';
            else
                return false;
        }
        return (s == num);
    }
};