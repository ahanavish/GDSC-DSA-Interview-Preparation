// https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        TreeNode *rooot = root;

        solve(rooot, ans);
        return ans;
    }

    void solve(TreeNode *node, vector<int> &ans)
    {
        if (node->left)
            solve(node->left, ans);
        ans.push_back(node->val);
        if (node->right)
            solve(node->right, ans);
    }
};