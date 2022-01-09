// https://leetcode.com/problems/subsets-ii/
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> row;

        sort(nums.begin(), nums.end());
        solve(nums, ans, row, 0);
        return ans;
    }

    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &row, int ind)
    {
        ans.push_back(row);

        for (int i = ind; i < nums.size(); i++)
        {
            if (i > ind and nums[i] == nums[i - 1])
                continue;

            row.push_back(nums[i]);
            solve(nums, ans, row, i + 1);
            row.pop_back();
        }
    }
};