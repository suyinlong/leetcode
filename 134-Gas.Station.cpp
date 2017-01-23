class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0, start = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            tank += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (tank < 0) {
                tank = 0;
                start = i + 1;
            }
        }
        return (sum < 0) ? -1 : start;
    }
};