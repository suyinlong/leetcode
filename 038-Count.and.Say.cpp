class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        if (n == 2) return "11";
        string last = countAndSay(n-1);
        string result = "";
        int count = 1;
        for (int i = 1; i < last.size(); i++) {
            if (last[i] != last[i-1]) {
                result.push_back('0'+count);
                result.push_back(last[i-1]);
                count = 1;
            }
            else
                count++;
            if (i == last.size() - 1) {
                result.push_back('0'+count);
                result.push_back(last[i]);
            }
        }
        return result;
    }
};