// https://leetcode.com/problems/basic-calculator/

class Solution {
public:
    int calculate(string s) 
    {
        int sum=0, sign = 1;
        stack <char> st;
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == ' ')
            {
                continue;
            }
            else if(isdigit(s[i]))
            {
                int num=0;
                while(isdigit(s[i]) && i<s.length())
                {
                    num = num*10 + s[i] - '0';
                    i++;
                }
                sum += num*sign;
                i--;
            }
            else if(s[i] == '(')
            {
                st.push(sum);
                st.push(sign);
                sum = 0;
                sign = 1;
            }
            else if(s[i] == ')')
            {
                sum *= st.top();
                st.pop();
                sum += st.top();
                st.pop();
            }
            else if(s[i] == '+')
                sign = 1;
            else if(s[i] == '-')
                sign = -1;
        }
        return sum;
    }
};