class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        stack<int> s;
        for (int p: preorder) {
            if (p < low) return false;
            while (!s.empty() && p > s.top()) {
                low = s.top();
                s.pop();
            }
            s.push(p);
        }
        return true;
    }
};