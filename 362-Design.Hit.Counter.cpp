class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {

    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (q.empty() || q.back().first != timestamp)
            q.push(make_pair(timestamp, 1));
        else
            q.back().second += 1;

        while (!q.empty() && q.back().first - q.front().first >= 300) {
            counter -= q.front().second;
            q.pop();
        }

        counter += 1;
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!q.empty() && timestamp - q.front().first >= 300) {
            counter -= q.front().second;
            q.pop();
        }
        return counter;
    }
private:
    int counter = 0, ts = 1;
    queue<pair<int, int>> q;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */