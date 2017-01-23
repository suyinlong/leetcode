class Solution {
    /*
    struct TrieNode {
        TrieNode *child[26] = {};
        bool isWord = false;
    };
    */
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        if (words.size() <= 1)
            return result;
        /*
        TrieNode *root = buildTrie(words);
        */
        unordered_set<string> wordDict(words.begin(), words.end());

        for (string s: words) {
            int len = s.size();
            vector<int> dp(len + 1, -1);
            dp[0] = 0;

            for (int i = 0; i < len; i++) {
                if (dp[i] >= 0) {
                    /*
                    TrieNode *node = root;
                    int j = i;
                    while (node->child[s[j] - 'a'] != NULL && j < len) {
                        node = node->child[s[j] - 'a'];
                        j++;
                        if (node->isWord) {
                            dp[j] = dp[i] + 1;
                            if (dp[len] >= 2) break;
                        }
                    }
                    */

                    for (int j = i; j < len; j++) {
                        if (wordDict.count(s.substr(i, j - i  + 1))) {
                            dp[j+1] = dp[i] + 1;
                            if (dp[len] >= 2) break;
                        }
                    }

                }
                if (dp[len] >= 2) break;
            }

            if (dp[len] >= 2)
                result.push_back(s);
        }
        return result;
    }
    /*
private:
    TrieNode *buildTrie(vector<string> &words) {
        TrieNode *root = new TrieNode();
        for (string s: words) {
            TrieNode *node = root;
            for (int i = 0; i < s.size(); i++) {
                int idx = s[i] - 'a';
                if (node->child[idx] == NULL)
                    node->child[idx] = new TrieNode();
                node = node->child[idx];
            }
            node->isWord = true;
        }
        return root;
    }
    */
};