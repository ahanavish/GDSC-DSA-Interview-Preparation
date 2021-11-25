// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int start = -1, end = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            end += nums[i];
            if (start < nums[i])
                start = nums[i];
        }
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            cout << mid;
            if (check(nums, m, mid))
                end = mid;
            else
                start = mid + 1;
        }
        return end;
    }

    bool check(vector<int> &nums, int m, int mid)
    {
        int i = 0, sum = 0, part = 1;
        while (i < nums.size())
        {
            if (sum + nums[i] <= mid)
                sum += nums[i++];
            else
            {
                sum = 0;
                part++;
            }

            if (part > m)
                return false;
        }
        cout << part << " ";
        return true;
    }
};