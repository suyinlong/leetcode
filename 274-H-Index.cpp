class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> buckets(n + 1, 0);
        for (int c: citations) {
            if (c > n)
                buckets[n]++;
            else
                buckets[c]++;
        }
        int total = 0;
        for (int i = n; i >= 0; i--) {
            total += buckets[i];
            if (total >= i)
                return i;
        }
        return 0;
    }
};