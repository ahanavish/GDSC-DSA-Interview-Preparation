// https://leetcode.com/problems/asteroid-collision/submissions/

class Solution {
public:
    stack <int> st;
    vector<int> asteroidCollision(vector<int>& v) 
    {
        for(int i=0; i<v.size(); i++)
        {
            if(v[i]>0 || st.empty())
                st.push(v[i]);
            else
            {
                while(!st.empty() && st.top()>0 && st.top()<abs(v[i]))
                    st.pop();
                if(!st.empty() && abs(v[i])==st.top())
                    st.pop();
                else if (st.empty() || st.top()<0)
                    st.push(v[i]);
            }
        }
        
        vector <int> vv;
        while(!st.empty())
        {
            vv.push_back(st.top());
            st.pop();
        }
        
        reverse(vv.begin(), vv.end());
        
        return vv;
    }
};