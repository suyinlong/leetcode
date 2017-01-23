class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            result = max(result, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) i++;
            else j--;
        }
        return result;
    }
};