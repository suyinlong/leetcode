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
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder, int i_s, int i_e, int p_s, int p_e) {
        TreeNode *root = new TreeNode(postorder[p_e]);
        if (i_s == i_e && p_s == p_e)
            return root;
        int k;
        for (k = i_s; k <= i_e; k++)
            if (inorder[k] == postorder[p_e])
                break;
        if (k != i_s)
            root->left = buildTree(inorder, postorder, i_s, k - 1, p_s, p_s + k - i_s - 1);
        if (k != i_e)
            root->right = buildTree(inorder, postorder, k + 1, i_e, p_s + k - i_s, p_e - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size() || inorder.size() == 0)
            return NULL;
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};