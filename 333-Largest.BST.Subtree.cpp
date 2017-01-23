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
    int largestBSTSubtree(TreeNode* root) {
        int maxSize = 0, subMin = INT_MAX, subMax = INT_MIN, subNum = 0;
        findSubBST(root, maxSize, subMin, subMax, subNum);
        return maxSize;
    }
    bool findSubBST(TreeNode *root, int &maxSize, int &subMin, int &subMax, int &subNum) {
        if (!root) {
            subNum = 0;
            return true;
        }
        int leftMin, leftMax, leftNum, rightMin, rightMax, rightNum;
        bool leftBST = findSubBST(root->left, maxSize, leftMin, leftMax, leftNum);
        bool rightBST = findSubBST(root->right, maxSize, rightMin, rightMax, rightNum);

        subNum = leftNum + rightNum + 1;
        subMin = root->val;
        subMax = root->val;
        if (leftNum > 0) {
            subMin = min(subMin, leftMin);
            subMax = max(subMax, leftMax);
        }
        if (rightNum > 0) {
            subMin = min(subMin, rightMin);
            subMax = max(subMax, rightMax);
        }

        if (!leftBST || !rightBST || (leftNum > 0 && leftMax >= root->val) || (rightNum > 0 && rightMin <= root->val))
            return false;
        maxSize = max(maxSize, subNum);
        return true;
    }
};