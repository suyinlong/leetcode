class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return decode(s, pos);
    }

    string decode(string &s, int &pos) {
        string result;
        int rep = 0;

        while (pos < s.size()) {
            if (s[pos] >= '0' && s[pos] <= '9') {
                rep *= 10;
                rep += s[pos] - '0';
                pos++;
            }
            else if (s[pos] == '[') {
                pos++;
                string r = decode(s, pos);
                for (int i = 0; i < rep; i++)
                    result += r;
                rep = 0;
            }
            else if (s[pos] == ']') {
                pos++;
                return result;
            }
            else {
                result += s[pos];
                pos++;
            }
        }
        return result;
    }
};