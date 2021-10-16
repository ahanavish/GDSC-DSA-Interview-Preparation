// https://leetcode.com/problems/linked-list-cycle-ii

class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(!head) 
            return NULL;
        
        if(!head->next)
            return NULL;
    
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) 
                break;
        }

        if(fast == slow)
        {
            slow = head;
            while(slow != fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        } 
        else
            return NULL;
    }
};