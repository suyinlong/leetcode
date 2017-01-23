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
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder, int p_s, int p_e, int i_s, int i_e) {
        TreeNode *root = new TreeNode(preorder[p_s]);
        if (p_s == p_e && i_s == i_e)
            return root;
        int k;
        for (k = i_s; k <= i_e; k++)
            if (inorder[k] == preorder[p_s])
                break;
        if (k != i_s)
            root->left = buildTree(preorder, inorder, p_s + 1, p_s + k - i_s, i_s, k - 1);
        if (k != i_e)
            root->right = buildTree(preorder, inorder, p_s + k - i_s + 1, p_e, k + 1, i_e);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != inorder.size() || preorder.size() == 0)
            return NULL;
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};