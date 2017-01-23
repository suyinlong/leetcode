class Solution {
public:
    int nthUglyNumber(int n) {
        long long r = 1;
        if (n == 1)
            return (int)r;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int i = 2; i <= n; i++) {
            if (r * 2 > 0) pq.push(r * 2);
            if (r * 3 > 0) pq.push(r * 3);
            if (r * 5 > 0) pq.push(r * 5);
            r = pq.top();
            while (!pq.empty() && pq.top() == r)
                pq.pop();
        }
        return (int)r;
    }
};