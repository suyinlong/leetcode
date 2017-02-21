class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        int n = target.size(), check = 0;
        vector<int> features;

        for (string w: dictionary) {
            if (w.size() != n) continue;
            int f = 0;
            for (int i = 0; i < n; i++)
                if (target[i] != w[i]) f += 1 << (n - 1 - i);
            features.push_back(f);
            check |= f;
        }

        int minAb = 0, minLen = INT_MAX;
        dfs(0, 0, features, check, n, minAb, minLen);

        string abbr;
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            if (i == n) {
                if (cnt > 0) abbr += to_string(cnt);
            }
            else {
                if ((minAb & (1 << (n - 1 - i))) == 0) cnt++;
                else {
                    if (cnt > 0) abbr += to_string(cnt);
                    cnt = 0;
                    abbr += target[i];
                }
            }

        }
        return abbr;
    }
private:
    void dfs(int pos, int mask, vector<int> &features, int &check, int n, int &minAb, int &minLen) {
        int len = calcLen(mask, n);
        if (len >= minLen) return;
        bool flag = true;
        for (int f: features)
            if ((mask & f) == 0) {
                flag = false;
                break;
            }
        if (flag) {
            minLen = len;
            minAb = mask;
        }
        else {
            for (int p = pos; p < n; p++)
                if (check & (1 << (n - 1 - p))) dfs(p + 1, mask + (1 << (n - 1 - p)), features, check, n, minAb, minLen);
        }
    }
    int calcLen(int mask, int n) {
        int len = 0, i = 0;
        while (i < n) {
            if ((mask & (1 << (n - 1 - i))) == 0) {
                len++;
                while (i < n && ((mask & (1 << (n - 1- i))) == 0)) i++;
            }
            else {
                len++;
                i++;
            }
        }
        return len;
    }
};