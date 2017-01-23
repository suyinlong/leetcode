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
        if (root->right)
            treeTraversal(root->right, result);
        result.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root)
            return result;
        treeTraversal(root, result);
        return result;
    }
};

/*
    Iterative solution using stack:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root)
            return result;

        stack<TreeNode*> s;
        TreeNode *node = root;
        while (node || !s.empty()) {
            if (node) {
                result.push_back(node->val);
                if (node->left)
                    s.push(node->left);
                node = node->right;
            }
            else {
                node = s.top();
                s.pop();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
 */