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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // head==null, k>len,  k<=0       
        if(k<=1 || head==NULL)
            return head;
        
        ListNode dummy(0);
        ListNode *p1 = &dummy;
        p1->next = head;
        while(1)
        {
            ListNode *p2 = p1->next;
            int count = k;
            while(p2 && count>0)
            {
                p2 = p2->next;     
                count--;
            }
            if(count>0)
                break;
            else
            {
                ListNode *p3 = p1->next; 
                ListNode *p4 = p3->next;
                assert(p4!=p2);
                while(p4!=p2)
                {
                    ListNode *tmp = p4->next;    
                    p4->next = p3;
                    p3 = p4;
                    p4 = tmp;
                }
                p1->next->next = p2;
                p2 = p1->next;
                p1->next = p3;
                p1 = p2;
            }
        }

        return dummy.next;
    }
};
