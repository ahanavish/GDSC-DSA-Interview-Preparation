// https://www.interviewbit.com/problems/palindrome-list/

int Solution::lPalin(ListNode* A) 
{
    ListNode *end=A;
    vector <int> v;
    int l=0; 

    while(end != NULL)
    {
        v.push_back(end->val);
        end = end->next;
        l++;
    }

    l--;
    int i=0;
    while(i < l)
    {
        if(v[i] != v[l])
            return 0;
        i++;
        l--;
    }
    return 1;
}