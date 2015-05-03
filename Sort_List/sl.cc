// this is the iterative version, therefore using constant memory

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode *dummy = new ListNode(0);    
        dummy->next = head;

        int count,total_l;
        ListNode *p1 = dummy; 
        while(p1->next)
        {
            total_l++;
            p1=p1->next;
        }
        
        int ml = 1;
        while(ml<total_l)
        {
        p1 = dummy;
        ListNode *p2;
        ListNode *p3;
        while(1)
        {
            p2 = p1->next;
            count = 0;
            while(p2 && count<ml)
            {
                p2 = p2->next;
                count++; 
            }
            if(p2 == NULL)
                break;
            else
            {
                count = 0; 
                p3 = p2;
                while(p3 && count<ml)
                {
                    p3 = p3->next;
                    count++; 
                }
                // do the merge
                ListNode *temp1 = p1->next;
                ListNode *temp2 = p2;
                while(temp1!=p2 && temp2!=p3)
                {
                    if(temp1->val < temp2->val) 
                    {
                        p1->next = temp1;     
                        temp1 = temp1->next;
                    }
                    else
                    {
                        p1->next = temp2; 
                        temp2 = temp2->next;
                    }
                    p1 = p1->next;
                }
                if(temp1!=p2)
                {
                    p1->next = temp1; 
                    while(p1->next!=p2)
                        p1 = p1->next; 
                    p1->next = p3;
                }
                else
                {
                    assert(p1->next == p2); 
                    p1->next = temp2;
                    while(p1->next!=p3)
                        p1 = p1->next;
                }
            }
        }
        
        ml *= 2;
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};
