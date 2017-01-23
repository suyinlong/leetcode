class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        wordList.insert(beginWord);
        wordList.insert(endWord);

        vector<string> vdict(wordList.begin(), wordList.end());
        int vstart = 0, vend = 0, n = vdict.size(), m = beginWord.size();
        for (int i = 0; i < n; i++) {
            if (vdict[i] == beginWord) vstart = i;
            if (vdict[i] == endWord) vend = i;
        }
        vector<vector<int>> prev(n);
        vector<int> distance(n, INT_MAX);

        queue<int> q;
        q.push(vstart);
        distance[vstart] = 0;

        while (!q.empty()) {
            int p = q.front();
            q.pop();
            if (p == vend) break;
            int d = distance[p] + 1;

            for (int i = 0; i < n; i++) {
                if (distance[i] < d) continue;
                int diff = 0;
                for (int j = 0; j < m; j++)
                    if (vdict[p][j] != vdict[i][j]) diff++;
                if (diff == 1) {
                    prev[i].push_back(p);
                    if (distance[i] > d)
                        q.push(i);
                    distance[i] = d;
                }
            }
        }

        vector<vector<string>> result;
        vector<string> current;
        getPaths(vstart, vend, vdict, prev, current, result);
        return result;
    }
private:
    void getPaths(int start, int end, vector<string> &vdict, vector<vector<int>> &prev, vector<string> &current, vector<vector<string>> &result) {
        current.push_back(vdict[end]);
        if (start == end) {
            reverse(current.begin(), current.end());
            result.push_back(current);
            reverse(current.begin(), current.end());
        }
        else {
            for (int i = 0; i < prev[end].size(); i++)
                getPaths(start, prev[end][i], vdict, prev, current, result);
        }
        current.pop_back();
    }
};