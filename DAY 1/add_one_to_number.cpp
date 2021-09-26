//https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &a)
{
 reverse(a.begin(), a.end());
 vector<int> sol;
 int carry = 1;
 for (int i = 0; i < a.size(); i++)
 {
 int sum = a[i] + carry;
 sol.push_back(sum%10);
 carry = sum / 10;
 }
 while (carry)
 {
 sol.push_back(carry%10);
 carry /= 10;
 }
 while (sol[sol.size() - 1] == 0 && sol.size() > 1)
 sol.pop_back();
 
 reverse(sol.begin(), sol.end());
 return sol;
}
