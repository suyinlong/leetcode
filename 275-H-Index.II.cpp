class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), l = 0, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (citations[m] < n - m) l = m + 1;
            else r = m;
        }
        return n - r;
    }
};