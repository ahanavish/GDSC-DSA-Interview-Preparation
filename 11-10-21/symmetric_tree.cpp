// https://leetcode.com/problems/symmetric-tree/

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;

        return symm(root->left, root->right);
    }

    bool symm(TreeNode *n1, TreeNode *n2)
    {
        if (!n1 && !n2) // both are null
            return true;

        if (!n1 || !n2) // one of them is null
            return false;

        if (n1->val != n2->val) // value isnt same
            return false;

        return symm(n1->left, n2->right) && symm(n1->right, n2->left);
    }
};