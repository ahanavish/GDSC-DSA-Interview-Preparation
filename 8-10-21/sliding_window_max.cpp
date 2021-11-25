// https://leetcode.com/problems/sliding-window-maximum/

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        multiset<int> s;
        vector<int> result;

        for (int i = 0; i < k; i++)
            s.insert(nums[i]); //using multiset to store first k elements

        for (int i = k; i < nums.size(); i++)
        {
            result.push_back(*s.rbegin()); // Adding the last element in the result - which is the largest element
            s.erase(s.find(nums[i - k]));  // erasing the first element in the existing window
            s.insert(nums[i]);             // inserting the new element in the set i.e incrementing window
        }

        result.push_back(*s.rbegin());
        return result;
    }
};