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
private:
    void generateTrees(int a, int b, vector<vector<vector<TreeNode*>>> &dp) {
        if (dp[a][b].size() > 0)
            return;
        if (a > b) {
            dp[a][b].push_back(NULL);
            return;
        }
        if (a == b) {
            dp[a][b].push_back(new TreeNode(a));
            return;
        }
        vector<TreeNode*> current;
        for (int i = a; i <= b; i++) {
            generateTrees(a, i-1, dp);
            generateTrees(i+1, b, dp);
            for (int j = 0; j < dp[a][i-1].size(); j++)
                for (int k = 0; k < dp[i+1][b].size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = dp[a][i-1][j];
                    root->right = dp[i+1][b][k];
                    current.push_back(root);
                }
        }
        dp[a][b] = current;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode*>();
        vector<vector<vector<TreeNode*>>> dp(n + 2, vector<vector<TreeNode*>>(n + 2));
        generateTrees(1, n, dp);
        return dp[1][n];
    }
};