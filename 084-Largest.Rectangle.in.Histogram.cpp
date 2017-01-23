class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> stk;
        int n = heights.size(), maxA = 0;
        for (int i = 0; i < n; i++) {
            if (stk.empty() || heights[i] >= heights[stk.top()])
                stk.push(i);
            else {
                while (!stk.empty() && heights[i] < heights[stk.top()]) {
                    int h = heights[stk.top()];
                    stk.pop();
                    maxA = max(maxA, h * (stk.empty() ? i : i - stk.top() - 1));
                }
                stk.push(i);
            }
        }
        return maxA;
    }
};