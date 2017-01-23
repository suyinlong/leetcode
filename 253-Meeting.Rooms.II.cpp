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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n <= 1)
            return n;
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) { return ((a.start < b.start) || (a.start == b.start && a.end < b.end)); });
        priority_queue<int, vector<int>, greater<int>> pq;
        for (Interval i: intervals) {
            if (!pq.empty() && pq.top() <= i.start)
                pq.pop();
            pq.push(i.end);
        }
        return pq.size();
    }
};