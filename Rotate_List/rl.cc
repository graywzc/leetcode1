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
    ListNode *rotateRight(ListNode *head, int k) {
        //edge: 1. head=null 2. k>lenth        
        if(head == NULL) return NULL;

        ListNode *p1 = head;
        int length = 1;
        while(p1->next)
        {
            length++;
            p1=p1->next;
        }
        k = k%length;
        if(k == 0) return head;
        p1->next = head;

        k = length-k;
        ListNode *p2 = p1->next;
        while(k>0)
        {
            p1 = p2;
            p2 = p2->next;
            k--; 
        }

        p1->next = NULL;
        return p2;
        
    }
};
