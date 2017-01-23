class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int c: nums) {
            if (pq.size() < k)
                pq.push(c);
            else if (pq.top() < c) {
                pq.pop();
                pq.push(c);
            }
        }
        return pq.top();
    }
};