// https://leetcode.com/problems/rotate-list/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == NULL)
            return NULL;
        
        ListNode *p = head;
        int len=0;
        while(p)
        {
            len++;
            p = p->next;
        }
        k=k%len;
        
        if(k==0)
            return head;
        
        p = NULL;
        ListNode *r = NULL;
        
        for(int i=0; i<k; i++)
            head = rotate(head);
        
        return head;
    }
    
    ListNode* rotate(ListNode* head)
    {
        ListNode* p = head, *q = NULL;
        
        while(p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        
        q->next = NULL;
        p->next = head;
        head = p;
        
        return head;
    }
};