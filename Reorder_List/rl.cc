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
    void reorderList(ListNode *head) {
        if(head==NULL || head->next == NULL || head->next->next==NULL)            
            return;

        ListNode *p1 = head;
        ListNode *p2 = head;

        while(p2->next && p2->next->next)
        {
            p1 = p1->next; 
            p2 = p2->next->next;
        }
        // reverse list after p1
        ListNode *mid = p1;
        p1 = mid->next; 
        p2 = p1->next;
        p1->next = NULL;
        ListNode *p3;
        while(p2)
        {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        mid->next = NULL;

        // insert node
        ListNode *p4;
        p3 = head;
        while(p1) 
        {
            p2 = p1->next; 
            p4 = p3->next; 
            p3->next = p1;
            p1->next = p4;
            p1 = p2;
            p3 = p4;
        }

        return;
        
    }
};
