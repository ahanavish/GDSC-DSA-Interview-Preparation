// https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL && l2 == NULL)
            return l1;
        else if(l1 == NULL && l2 != NULL)
            return l2;
        else if(l1 != NULL && l2 == NULL)
            return l1;
        
        ListNode *head = NULL;
        if(l1->val>l2->val)
        {
            head = l2;
            l2 = l2->next;
        }
        else                                            //     head
        {                                               //l1     1    2   4                            
            head = l1;                                  //l2     1    3   4
            l1 = l1->next;
        }
    
        ListNode *t = head;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val > l2->val)
            {
                t->next = l2;
                t = l2;
                l2 = l2->next;
            }
            else
            {
                t->next = l1;
                t = l1;
                l1 = l1->next;
            }
        }
        
        if(l1 != NULL)
            t->next = l1;
        
        if(l2 != NULL)
            t->next = l2;
        
        return head;
    }
};