// https://leetcode.com/problems/balanced-binary-tree/

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        vector<int> ans;

        int h = is(root, ans);

        if (check(ans))
            return true;
        else
            return false;
    }

    bool check(vector<int> &ans)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] - ans[i + 1] > 1 || ans[i + 1] - ans[i] > 1)
                return false;
            i++;
        }
        return true;
    }

    int is(TreeNode *node, vector<int> &ans)
    {
        if (!node)
            return 0;

        int l = is(node->left, ans), r = is(node->right, ans);
        ans.push_back(l);
        ans.push_back(r);
        return max(l, r) + 1;
    }
};