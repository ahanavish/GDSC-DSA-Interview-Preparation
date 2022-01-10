// https://leetcode.com/problems/binary-tree-preorder-traversal/

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        solve(root, ans);
        return ans;
    }

    void solve(TreeNode *node, vector<int> &ans)
    {
        ans.push_back(node->val);
        if (node->left)
            solve(node->left, ans);
        if (node->right)
            solve(node->right, ans);
    }
};