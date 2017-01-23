/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<pair<TreeNode*, bool>> _nStack;
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            _nStack.push(pair<TreeNode*, bool>(root, false));
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !_nStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = _nStack.top().first;
        int r = node->val;
        _nStack.top().second = true;

        if (node->right) {
            node = node->right;
            while (node) {
                _nStack.push(pair<TreeNode*, bool>(node, false));
                node = node->left;
            }
        }
        else {
            while (!_nStack.empty() && _nStack.top().second == true)
                _nStack.pop();
        }

        return r;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */