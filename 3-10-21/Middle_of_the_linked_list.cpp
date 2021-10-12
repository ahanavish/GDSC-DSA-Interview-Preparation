// https://leetcode.com/problems/middle-of-the-linked-list/

class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *p= head;
        ListNode *q = p;
        
        while(p != NULL && p->next != NULL)
        {
            q = q->next;
            p = p->next->next;
        }
        return q;
    }
};