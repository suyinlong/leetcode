class Solution {
    struct Ugly {
        int val;
        int prime;
        int idx;
        Ugly(int v, int p, int i) : val(v), prime(p), idx(i) {}
    };
    struct cmp {
        bool operator()(Ugly a, Ugly b){
            return a.val > b.val;
        }
    };
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1)
            return 1;

        vector<int> dp(n, 0);
        dp[0] = 1;

        priority_queue<Ugly, vector<Ugly>, cmp> heap;
        for (int p: primes)
            heap.push(Ugly(p, p, 0));

        for (int i = 1; i < n; i++) {
            dp[i] = heap.top().val;
            while (!heap.empty() && heap.top().val == dp[i]) {
                Ugly next = heap.top();
                heap.pop();
                next.idx++;
                next.val = dp[next.idx] * next.prime;
                heap.push(next);
            }
        }
        return dp[n-1];
    }
};