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
    void treeTraversal(TreeNode *root, vector<int> &result) {
        if (root->left)
            treeTraversal(root->left, result);
        result.push_back(root->val);
        if (root->right)
            treeTraversal(root->right, result);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root)
            return result;
        treeTraversal(root, result);
        return result;
    }
};

/*
    Iterative solution using stack:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode *curNode = root;

        while (curNode || !s.empty()) {
            if (curNode) {
                s.push(curNode);
                curNode = curNode->left;
            }
            else {
                curNode = s.top();
                s.pop();
                result.push_back(curNode->val);
                curNode = curNode->right;
            }
        }
        return result;
    }
 */

/*
    Morris traversal:
    vector<int> inorderTraversal(TreeNode* root) {
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
                    curNode = curNode->left;
                }
                else {
                    prev->right = NULL;
                    result.push_back(curNode->val);
                    curNode = curNode->right;
                }
            }
        }
        return result;
    }
 */
