class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if (n == 0 || duration == 0) return 0;

        int startTime = timeSeries[0], endTime = startTime + duration - 1, poi = 0;
        for (int i = 0; i <= n; i++) {
            if (i == n) {
                poi += endTime - startTime + 1;
            }
            else {
                if (timeSeries[i] <= endTime)
                    endTime = timeSeries[i] + duration - 1;
                else {
                    poi += endTime - startTime + 1;
                    startTime = timeSeries[i];
                    endTime = startTime + duration - 1;
                }
            }
        }
        return poi;
    }
};