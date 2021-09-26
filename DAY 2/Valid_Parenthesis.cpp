//https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) 
    {
        int n=s.length();
        if(n%2!=0)  
            return false;
        stack <char> st;
        
        for(int i=0; i<n; i++)
        {
            char c = s[i];
            if((c=='}')||(c==']')||(c==')'))
            {
               if(st.empty()) 
                   return false;
               switch(st.top())
               {
                   case '(' : if(c!=')') return false;
                              break;
                   case '{' : if(c!='}') return false;
                              break;
                   case '[' : if(c!=']') return false;
                              break; 
               }
               st.pop();
            }
            else
                st.push(c);
        }
        return st.empty();
    }
};