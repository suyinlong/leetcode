class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result(k, 0);
        vector<vector<int>> maxNums1(k + 1), maxNums2(k + 1);
        dpNums(nums1, maxNums1, k);
        dpNums(nums2, maxNums2, k);
        for (int i = 0; i <= k; i++) {
            if (maxNums1[i].size() + maxNums2[k-i].size() < k) continue;
            vector<int> current = merge(maxNums1[i], maxNums2[k-i]);
            if (comp(result, current))
                result = current;
        }
        return result;
    }

private:
    void dpNums(vector<int> &nums, vector<vector<int>> &maxNums, int k) {
        int i = 0;
        while (nums.size() > 0) {
            if (nums.size() <= k)
                maxNums[nums.size()] = nums;
            for ( ; i < nums.size() - 1 && nums[i] >= nums[i+1]; i++);
            nums.erase(nums.begin() + i);
            i = (i > 0) ? i - 1 : 0;
        }
    }

    vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
        vector<int> current(nums1.size() + nums2.size(), 0);
        int i = 0, j = 0;
        for ( ; i < nums1.size() && j < nums2.size(); ) {
            if (nums1[i] > nums2[j]) {
                current[i+j] = nums1[i];
                i++;
            }
            else if (nums1[i] < nums2[j]) {
                current[i+j] = nums2[j];
                j++;
            }
            else {
                int ii = i, jj = j;
                while (ii < nums1.size() && jj < nums2.size() && nums1[ii] == nums2[jj]) ii++, jj++;
                if (jj >= nums2.size() || (ii < nums1.size() && nums1[ii] >= nums2[jj])) {
                    current[i+j] = nums1[i];
                    i++;
                }
                else {
                    current[i+j] = nums2[j];
                    j++;
                }
            }
        }
        for ( ; i < nums1.size(); i++)
            current[i+j] = nums1[i];
        for ( ; j < nums2.size(); j++)
            current[i+j] = nums2[j];
        return current;
    }

    bool comp(vector<int> &result, vector<int> &current) {
        for (int i = 0; i < result.size(); i++) {
            if (result[i] > current[i]) return false;
            else if (result[i] < current[i]) return true;
        }
        return false;
    }


};