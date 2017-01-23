class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        if (n == 0) return "";

        vector<vector<bool>> adj(26, vector<bool>(26, false));
        vector<int> indegree(26, -1);

        for (char c: words[0])
            indegree[c-'a'] = 0;

        for (int k = 1; k < n; k++) {
            for (char c: words[k])
                if (indegree[c-'a'] == -1)
                    indegree[c-'a'] = 0;
            int i = 0, j = 0;
            while (i < words[k-1].size() && j < words[k].size() && words[k-1][i] == words[k][j]) {
                i++;
                j++;
            }
            if (i < words[k-1].size() && j < words[k].size()) {
                int n1 = words[k-1][i] - 'a', n2 = words[k][j] - 'a';
                if (!adj[n1][n2]) {
                    adj[n1][n2] = true;
                    indegree[n2]++;
                }
            }
            if (i < words[k-1].size() && j == words[k].size())
                return "";
        }

        unordered_set<int> zeroes;
        int cnt = 0;
        string res = "";
        for (int i = 0; i < 26; i++) {
            if (indegree[i] >= 0) cnt++;
            if (indegree[i] == 0) zeroes.insert(i);
        }
        while (!zeroes.empty()) {
            auto it = zeroes.begin();
            int w = *it;
            res += (char)(w + 'a');
            for (int ww = 0; ww < 26; ww++) {
                if (adj[w][ww]) {
                    indegree[ww]--;
                    if (indegree[ww] == 0)
                        zeroes.insert(ww);
                }
            }
            zeroes.erase(w);
            cnt--;
        }
        if (cnt == 0)
            return res;
        else
            return "";
    }
};