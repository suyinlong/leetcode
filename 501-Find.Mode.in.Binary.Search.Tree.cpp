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
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        int occur = 0, cur_occur = 0;
        long long cur = LLONG_MIN;
        findMode(root, modes, occur, cur, cur_occur);
        return modes;
    }
    void findMode(TreeNode *root, vector<int> &modes, int &occur, long long &cur, int &cur_occur) {
        if (!root) return;

        findMode(root->left, modes, occur, cur, cur_occur);

        if (root->val == cur)
            cur_occur++;
        else {
            cur = root->val;
            cur_occur = 1;
        }
        if (cur_occur > occur) {
            modes.clear();
            modes.push_back(cur);
            occur = cur_occur;
        }
        else if (cur_occur == occur)
            modes.push_back(cur);

        findMode(root->right, modes, occur, cur, cur_occur);
    }
};