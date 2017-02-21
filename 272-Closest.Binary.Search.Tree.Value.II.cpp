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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<TreeNode*> pStk, sStk;

        initPredecessor(root, target, pStk);
        initSuccessor(root, target, sStk);

        if (!pStk.empty() && !sStk.empty() && pStk.top() == sStk.top())
            getPredecessor(pStk);

        while (k-- > 0) {
            if (sStk.empty())
                res.push_back(getPredecessor(pStk));
            else if (pStk.empty())
                res.push_back(getSuccessor(sStk));
            else if (abs(target - pStk.top()->val) < abs(target - sStk.top()->val))
                res.push_back(getPredecessor(pStk));
            else
                res.push_back(getSuccessor(sStk));
        }

        return res;
    }
    void initPredecessor(TreeNode *root, double target, stack<TreeNode*> &pStk) {
        while (root) {
            if (root->val == target) {
                pStk.push(root);
                break;
            }
            else if (root->val < target) {
                pStk.push(root);
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
    }
    int getPredecessor(stack<TreeNode*> &pStk) {
        TreeNode *node = pStk.top();
        pStk.pop();
        int ret = node->val;
        node = node->left;
        while (node) {
            pStk.push(node);
            node = node->right;
        }
        return ret;
    }
    void initSuccessor(TreeNode *root, double target, stack<TreeNode*> &sStk) {
        while (root) {
            if (root->val == target) {
                sStk.push(root);
                break;
            }
            else if (root->val > target) {
                sStk.push(root);
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
    }
    int getSuccessor(stack<TreeNode*> &sStk) {
        TreeNode *node = sStk.top();
        sStk.pop();
        int ret = node->val;
        node = node->right;
        while (node) {
            sStk.push(node);
            node = node->left;
        }
        return ret;
    }
};