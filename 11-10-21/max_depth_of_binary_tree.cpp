// https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return solve(root);
    }

    int solve(TreeNode *node)
    {
        if (!node)
            return 0;

        return max(solve(node->left), solve(node->right)) + 1;
    }
};