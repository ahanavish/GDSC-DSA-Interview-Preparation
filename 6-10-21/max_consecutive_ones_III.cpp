//https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& n, int k) 
    {
        int ans=0, lim=k, i=0, j=0;
        while(j<n.size())
        {
            if(n[j]== 1)
                j++;
            else if(n[j]==0 && lim!=0)
            {
                j++;
                lim--;
            }
            else
            {
                ans = max(ans, j-i);
                if(n[i] == 0)
                {
                    i++;
                    lim++;
                }
                else 
                    while(n[i] == 1)
                        i++;
            }
                
        }
        ans = max(ans, j-i);
        return ans;
    }
};