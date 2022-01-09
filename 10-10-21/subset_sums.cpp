// https://practice.geeksforgeeks.org/problems/subset-sums2234/1#

class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans;
        solve(arr, 0, n, 0, ans);
        return ans;
    }

    void solve(vector<int> arr, int i, int n, int sum, vector<int> &ans)
    {
        if (i == n)
        {
            ans.push_back(sum);
            return;
        }
        solve(arr, i + 1, n, sum + arr[i], ans);
        solve(arr, i + 1, n, sum, ans);
    }
};