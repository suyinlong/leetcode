class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0')
            return 0;
        if (s.length() == 1)
            return 1;

        int a = 1, b = 1, c;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '0')
                if (s[i-1] == '1' || s[i-1] == '2')
                    c = a;
                else
                    c = 0;
            else if (s[i-1] == '0' || stoi(s.substr(i-1,2)) > 26)
                c = b;
            else
                c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};