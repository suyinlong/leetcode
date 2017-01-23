/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n <= 1) return 0;
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) { return a.end < b.end; });
        int maxI = 1, fin = intervals[0].end;
        for (int i = 1; i < n; i++)
            if (intervals[i].start >= fin) {
                fin = intervals[i].end;
                maxI++;
            }
        return n - maxI;

    }
};