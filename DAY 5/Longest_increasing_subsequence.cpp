//https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans(n,1);
        
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
                if(nums[j]<nums[i])
                    ans[i] = max(ans[i],1+ans[j]);
        
        return *max_element(ans.begin(),ans.end());
    }
};