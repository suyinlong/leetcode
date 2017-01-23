class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord.length() != endWord.length())
            return 0;
        if (beginWord.empty() || endWord.empty())
            return 0;
        queue<string> sQueue;
        queue<int> lQueue;
        sQueue.push(beginWord);
        lQueue.push(1);

        while (wordList.size() > 0 && !sQueue.empty()) {
            string str(sQueue.front());
            int len = lQueue.front();
            sQueue.pop();
            lQueue.pop();

            for (int i = 0; i < str.length(); i++)
                for (int j = 'a'; j <= 'z'; j++) {
                    if (j == str[i])
                        continue;
                    char t = str[i];
                    str[i] = j;
                    if (str == endWord)
                        return len + 1;
                    if (wordList.count(str) > 0) {
                        sQueue.push(str);
                        lQueue.push(len + 1);
                        wordList.erase(str);
                    }
                    str[i] = t;
                }
        }
        return 0;
    }
};