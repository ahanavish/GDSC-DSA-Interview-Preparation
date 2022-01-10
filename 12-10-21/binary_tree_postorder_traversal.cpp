// https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        solve(root, ans);
        return ans;
    }
    void solve(TreeNode *node, vector<int> &ans)
    {
        if (node->left)
            solve(node->left, ans);
        if (node->right)
            solve(node->right, ans);
        ans.push_back(node->val);
    }
};