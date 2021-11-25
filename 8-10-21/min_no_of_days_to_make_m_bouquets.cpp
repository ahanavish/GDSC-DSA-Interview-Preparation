// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution
{
public:
    int minDays(vector<int> &b, int m, int k)
    {
        int size = b.size();
        if (size < m * k)
            return -1;

        int low = *min_element(b.begin(), b.end());
        int high = *max_element(b.begin(), b.end());

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (check(mid, b, m, k))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }

    bool check(int day, vector<int> &b, int m, int k)
    {
        int flow = 0, bouq = 0;
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] <= day)
            {
                flow++;
                if (flow == k)
                {
                    bouq++;
                    flow = 0;
                }
            }
            else
                flow = 0;
        }

        if (bouq >= m)
            return true;
        else
            return false;
    }
};