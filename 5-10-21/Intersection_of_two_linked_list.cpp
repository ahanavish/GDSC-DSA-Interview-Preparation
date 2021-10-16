// https://leetcode.com/problems/intersection-of-two-linked-lists/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA==NULL || headB==NULL)
            return NULL;
        
        ListNode *pa=headA,*pb=headB;
        
        int la=0, lb=0;
        while(pa != NULL)
        {
            pa = pa->next;
            la++;
        }
        while(pb != NULL)
        {
            pb = pb->next;
            lb++;
        }
        
        int diff=0;
        pa = headA, pb = headB;
        if(la<lb)
        {
            diff = lb-la;
            for(int i=0; i<diff; i++)
                pb = pb->next;
        }
        else
        {
            diff = la-lb;
            for(int i=0; i<diff; i++)
                pa = pa->next;
        }
        
        while(pa!=pb)
        {
            pa = pa->next;
            pb = pb->next;
            
            if(pa == NULL && pb == NULL)
                return NULL;
        }
        return pa;
    }
};