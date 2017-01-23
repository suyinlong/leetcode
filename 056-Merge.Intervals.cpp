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
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty() || intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            return a.start < b.start || (a.start ==  b.start && a.end <  b.end);
        });

        vector<Interval> result;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start > intervals[i-1].end)
                result.push_back(intervals[i-1]);
            else {
                intervals[i].start = intervals[i-1].start;
                intervals[i].end = max(intervals[i].end, intervals[i-1].end);
            }
            if (i == intervals.size() - 1)
                result.push_back(intervals[i]);
        }

        return result;
    }
};