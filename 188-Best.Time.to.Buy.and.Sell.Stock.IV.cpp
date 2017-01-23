class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k == 0 || n < 2)
            return 0;
        if (k >= n / 2) {
            int sum = 0;
            for (int i = 1; i < n; i++)
                if (prices[i] - prices[i-1] > 0)
                    sum += prices[i] - prices[i-1];
            return sum;
        }

        vector<int> buy(k, INT_MIN);
        vector<int> sell(k, 0);
        for (int p: prices) {
            for (int i = k - 1; i >= 0; i--) {
                sell[i] = max(sell[i], buy[i] + p);
                buy[i] = max(buy[i], (i > 0 ? sell[i-1] : 0) - p);
            }
        }
        return sell[k-1];
    }
};