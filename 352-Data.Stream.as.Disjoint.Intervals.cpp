/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
struct comp {
    bool operator()(const Interval &a, const Interval &b) {
        return a.start < b.start || (a.start == b.start && a.end < b.end);
    }
};
private:
    set<Interval, comp> container;
public:

    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        Interval I(val, val);
        auto l = container.lower_bound(I), r = container.upper_bound(I);

        if (l != container.begin() && prev(l)->end >= val - 1) {
            I.start = prev(l)->start;
            I.end = max(I.end, prev(l)->end);
            container.erase(prev(l));
        }
        if (l != container.end() && l->start <= val + 1) {
            I.start = min(l->start, I.start);
            I.end = l->end;
            container.erase(l);
        }
        container.insert(I);
    }

    vector<Interval> getIntervals() {
        return vector<Interval>(container.begin(), container.end());
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */