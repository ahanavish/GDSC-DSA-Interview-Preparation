//https://leetcode.com/problems/subarrays-with-k-different-integers/ 

class Solution {
public:
    int sub(vector<int>& nums, int k)
    {
        unordered_map<int,int> m;
        int n = nums.size(), i=0, unique=0, ans=0;
        
        for(int j=0; j<n; j++)
        {
            int curr = nums[j];
            if(m.find(curr) == m.end())        //if key is not present, iterator points to m.end()
                unique++;
            
            m[curr]++;
            
            while(unique > k)
            {
                m[nums[i]]--;
                if(m[nums[i]] == 0)
                {
                    m.erase(nums[i]);
                    unique--;
                } 
                i++;
            }
            ans += j-i+1;           //gives subarrays till 'j'
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& n, int k) 
    {
        return sub(n,k) - sub(n, k-1);
    }
};