class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int result = 0, n = heaters.size();
        sort(heaters.begin(), heaters.end());
        for (int h: houses) {
            if (h <= heaters[0])
                result = max(result, heaters[0] - h);
            else if (h >= heaters[n - 1])
                result = max(result, h - heaters[n - 1]);
            else {
                auto low_it = lower_bound(heaters.begin(), heaters.end(), h);
                auto upp_it = upper_bound(heaters.begin(), heaters.end(), h);
                if (low_it != upp_it) continue;
                int m = low_it - heaters.begin();

                result = max(result, min(heaters[m] - h, h - heaters[m-1]));
            }
        }
        return result;
    }
};