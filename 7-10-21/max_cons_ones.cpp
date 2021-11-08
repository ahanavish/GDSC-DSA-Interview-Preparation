// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& n) {
        int count=0, ans=0;
        for(int i=0; i<n.size(); i++)
        {
            if(n[i] == 1)
                count++;
            else
            {
                cout<<count;
                ans = max(ans, count);  //2
                count = 0;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};