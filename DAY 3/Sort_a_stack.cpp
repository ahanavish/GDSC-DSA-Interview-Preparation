// https://practice.geeksforgeeks.org/problems/sort-a-stack/1#

void sortedInsert(stack<int>&s,int x)
{
   if(s.empty() || x > s.top())
       s.push(x);
   else
   {
       int temp = s.top();
       s.pop();
       sortedInsert(s,x);
       s.push(temp);
   }
}
void SortedStack :: sort()
{
    if(!s.empty())
    {
        int temp = s.top();
        s.pop();
        sort();
        sortedInsert(s,temp);
    }
}