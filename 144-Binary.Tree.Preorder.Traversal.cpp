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
    void traversal(TreeNode *root, vector<int> &result) {
        if (!root)
            return;
        result.push_back(root->val);
        traversal(root->left, result);
        traversal(root->right, result);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

/*
    Iterative solution using stack:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root)
            return result;

        stack<TreeNode*> s;
        TreeNode *node = root;
        while (node || !s.empty()) {
            if (node) {
                result.push_back(node->val);
                if (node->right)
                    s.push(node->right);
                node = node->left;
            }
            else {
                node = s.top();
                s.pop();
            }
        }
        return result;
    }
 */

/*
    Morris traversal:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode *curNode = root;

        while (curNode) {
            if (curNode->left == NULL) {
                result.push_back(curNode->val);
                curNode = curNode->right;
            }
            else {
                TreeNode * prev = curNode->left;
                while (prev->right && prev->right != curNode)
                    prev = prev->right;
                if (prev->right == NULL) {
                    prev->right = curNode;
                    result.push_back(curNode->val);
                    curNode = curNode->left;
                }
                else {
                    prev->right = NULL;
                    curNode = curNode->right;
                }
            }
        }
        return result;
    }
 */