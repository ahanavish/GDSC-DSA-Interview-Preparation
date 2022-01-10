// https://leetcode.com/problems/same-tree/

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL) // both are not null
            return true;
        if (p == NULL || q == NULL) // checking if one of them is null
            return false;

        // checking value, then leftsubtree and then right subtree
        return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};