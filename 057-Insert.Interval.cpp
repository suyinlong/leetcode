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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result(intervals);
        auto it = result.begin();
        while (it != result.end()) {
            if (newInterval.end < it->start) {
                result.insert(it, newInterval);
                return result;
            }
            else if (newInterval.start > it->end) {
                it++;
            }
            else {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                it = result.erase(it);
            }
        }
        result.insert(result.end(), newInterval);
        return result;
    }
};