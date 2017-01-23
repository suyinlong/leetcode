class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int c1 = 0, c2 = 0, c3 = 0, tmpmax = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            c3 = max(c2, tmpmax + prices[i]);
            if (i >= 2) tmpmax = max(tmpmax, c1 - prices[i]);
            else tmpmax = max(tmpmax, -prices[i]);

            c1 = c2;
            c2 = c3;
        }
        return c3;
    }
};