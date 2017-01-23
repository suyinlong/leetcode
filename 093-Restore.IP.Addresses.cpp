class Solution {
public:
    void dtry(string &s, int pos, vector<string> &result, vector<string> &c) {
        if (pos == s.length() && c.size() == 4) {
            result.push_back(c[0] + "." + c[1] + "." + c[2] + "." + c[3]);
            return;
        }
        if (pos > s.length() || (c.size() == 4 && pos != s.length()))
            return;

        c.push_back(s.substr(pos, 1));
        dtry(s, pos+1, result, c);
        c.pop_back();
        if (s[pos] == '0')
            return;

        if (pos < s.length() - 1) {
            c.push_back(s.substr(pos, 2));
            dtry(s, pos+2, result, c);
            c.pop_back();
        }

        if (pos < s.length() - 2 && stoi(s.substr(pos, 3)) <= 255) {
            c.push_back(s.substr(pos, 3));
            dtry(s, pos+3, result,c);
            c.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> c;

        if (s.length() < 4)
            return result;
        dtry(s, 0, result, c);
        return result;
    }
};