/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sumCount;
        vector<int> sums;
        helper(root, sumCount, sums);
        return sums;
    }
    int helper(TreeNode *root, unordered_map<int, int> &sumCount, vector<int> &sums) {
        if (!root) return 0;
        int left = helper(root->left, sumCount, sums);
        int right = helper(root->right, sumCount, sums);
        int sum = root->val + left + right;
        sumCount[sum]++;
        if (sums.size() == 0)
            sums.push_back(sum);
        else if (sumCount[sum] > sumCount[sums[0]] || sum == sums[0]) {
            sums.clear();
            sums.push_back(sum);
        }
        else if (sumCount[sum] == sumCount[sums[0]]) {
            sums.push_back(sum);
        }
        return sum;
    }
};