// https://leetcode.com/problems/reverse-linked-list/

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL)
            return head;
        
        ListNode *q = head, *r = NULL;     //used for traversal
        
        while(q != NULL)
        {
            ListNode* p = q->next;
            q->next = r;
            r = q;
            q = p;
        }
        return r;
    }
};