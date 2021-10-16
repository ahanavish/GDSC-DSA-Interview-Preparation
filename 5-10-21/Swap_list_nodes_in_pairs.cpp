// https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

LiListNode* Solution::swapPairs(ListNode* start) 
{
    ListNode *p, *new_start, *q, *temp;
    p = start;
    if(p->next == NULL)
        return p;
    new_start = p->next;

    while(1)
    {
        q = p->next;
        temp = q->next;
        q->next = p;

        if(temp == NULL)
        {
            p->next = NULL;
            break;
        }

        if(temp->next == NULL)
        {
            p->next = temp;
            break;            
        }
        p->next = temp->next;
        p = temp;
    }
    return new_start;
}