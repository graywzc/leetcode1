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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode dummy(0);
        ListNode *pd = &dummy;
        while(l1&&l2)
        {
            int temp = l1->val+l2->val+carry; 
            pd->next = new ListNode(temp%10); 
            carry = temp/10;
            l1 = l1->next;
            l2 = l2->next;
            pd = pd->next;
        }
        while(l1)
        {
            int temp = l1->val+carry; 
            pd->next = new ListNode(temp%10); 
            carry = temp/10;
            pd = pd->next;
            l1 = l1->next;
        }
        while(l2)
        {
            int temp = l2->val+carry; 
            pd->next = new ListNode(temp%10); 
            carry = temp/10;
            pd = pd->next;
            l2 = l2->next;
        }
        if(carry==1)
            pd->next = new ListNode(1);
        return dummy.next;
    }
};
