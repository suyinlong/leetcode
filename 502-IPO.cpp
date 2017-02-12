class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int n = Profits.size();
        priority_queue<pair<int, int>> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < n; i++) {
            if (Capital[i] <= W)
                maxHeap.push(make_pair(Profits[i], Capital[i]));
            else
                minHeap.push(make_pair(Capital[i], Profits[i]));
        }
        while (k-- > 0) {
            if (maxHeap.empty()) return W;
            W += maxHeap.top().first;
            maxHeap.pop();
            while (!minHeap.empty() && minHeap.top().first <= W) {
                maxHeap.push(make_pair(minHeap.top().second, minHeap.top().first));
                minHeap.pop();
            }
        }
        return W;
    }
};