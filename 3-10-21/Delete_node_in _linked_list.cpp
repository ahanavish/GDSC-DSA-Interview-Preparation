// https://leetcode.com/problems/delete-node-in-a-linked-list/

class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        ListNode* p = node->next;       //pointer to the node which is next to the deleting node
        node->val = p->val;             //copy the value of next node to the value of deleting node
        node->next = p->next;           //copy the address of next-to-next node to the next of deleting node
        delete p;                       //delete the next node
    }
};