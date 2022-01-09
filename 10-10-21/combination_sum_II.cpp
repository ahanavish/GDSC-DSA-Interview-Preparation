// https://leetcode.com/problems/combination-sum-ii/

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &c, int t)
    {
        vector<vector<int>> ans;
        vector<int> row;

        sort(c.begin(), c.end());
        solve(c, ans, row, 0, t);
        return ans;
    }

    void solve(vector<int> c, vector<vector<int>> &ans, vector<int> &row, int ind, int t)
    {
        if (t <= 0)
        {
            if (t == 0)
                ans.push_back(row);
            return;
        }

        for (int i = ind; i < c.size(); i++)
        {
            if (i != ind && (c[i] == c[i - 1]))
                continue;
            row.push_back(c[i]);
            solve(c, ans, row, i + 1, t - c[i]);
            row.pop_back();
        }
    }
};