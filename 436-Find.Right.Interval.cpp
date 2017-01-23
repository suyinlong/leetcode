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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> idx;
        for (int i = 0; i < intervals.size(); i++)
            idx[intervals[i].start] = i;
        vector<int> result;
        for (int i = 0; i < intervals.size(); i++) {
            auto it = idx.lower_bound(intervals[i].end);
            result.push_back(it == idx.end() ? -1 : it->second);
        }
        return result;
    }
};