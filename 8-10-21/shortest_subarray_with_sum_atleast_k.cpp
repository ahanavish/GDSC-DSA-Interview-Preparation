// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {

        if (nums.size() == 1)
        {
            return nums[0] >= k ? 1 : -1;
        }

        vector<long> accVec;
        long acc = 0;
        accVec.push_back(acc);
        for (auto i : nums)
        {
            acc += i;
            accVec.push_back(acc);
        }

        int res = INT_MAX;
        deque<int> monoq;

        for (int y = 0; y < accVec.size(); ++y)
        {
            // want opt(y) = largest x with P[x] <= P[y] - K;
            while (!monoq.empty() && accVec[y] <= accVec[monoq.back()])
                monoq.pop_back();
            while (!monoq.empty() && accVec[y] >= accVec[monoq.front()] + k)
            {
                res = min(res, y - monoq.front());
                monoq.pop_front();
            }

            monoq.push_back(y);
        }

        return res == INT_MAX ? -1 : res;
    }
};