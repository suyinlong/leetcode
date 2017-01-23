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
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> preSum;
        preSum[0] = 1;
        int count = 0;
        pathHelper(root, 0, sum, preSum, count);
        return count;
    }
private:
    void pathHelper(TreeNode *root, int current, int sum, unordered_map<int, int> &preSum, int &count) {
        if (!root) return;
        current += root->val;

        if (preSum.find(current - sum) != preSum.end())
            count += preSum[current - sum];
        if (preSum.find(current) == preSum.end())
            preSum[current] = 0;
        preSum[current]++;
        pathHelper(root->left, current, sum, preSum, count);
        pathHelper(root->right, current, sum, preSum, count);
        preSum[current]--;

    }
};