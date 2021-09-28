// https://leetcode.com/problems/add-two-numbers-ii/

class Solution {
public:
    ListNode* reverse(ListNode* l)
    {
        ListNode *p = l, *q = 0, *r = 0;
        while(p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        return q;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    { 
        l1 = reverse(l1);
        l2 = reverse(l2);
    
        ListNode* head = new ListNode(0);
        ListNode* ans = head;
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* last= NULL;
        
        int carry = 0;
        while(a || b)
        {
            int sum=0;
            if(a)
            {
                sum = a->val;
                a = a->next;
            }
            
            if(b)
            {
                sum += b->val;
                b = b->next;
            }
            sum += carry;
            
            ListNode* temp = new ListNode(sum%10);
            ans->next = temp;
            ans = ans->next;
            carry = sum/10;
        }
        
        if(carry != 0)
        {
            ListNode* temp = new ListNode(carry);
            ans->next = temp;
            ans = ans->next;
        }
    
        ans = reverse(head->next);
        return ans;
    }
};