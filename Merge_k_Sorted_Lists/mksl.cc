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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int size = lists.size();                
        if(size == 0)
            return NULL;

        while(size>1)
        {
            int i = 0, j = 0; 
            while((i+1)<size)
            {
                ListNode dummy(0);
                ListNode *pd = &dummy;
                ListNode *p1 = lists[i];
                ListNode *p2 = lists[i+1];

                while(p1&&p2)
                {
                    if(p1->val<p2->val) 
                    {    
                        pd->next = p1;
                        p1 = p1->next;
                    }
                    else
                    {
                        pd->next = p2; 
                        p2 = p2->next;
                    }
                    pd = pd->next;
                }
                if(p1)
                    pd->next = p1;
                else
                    pd->next = p2;

                lists[j++] = dummy.next;
                i+=2; 
            }
            if(i<size)
                lists[j++] = lists[i]; 

            size = j;
        }
        return lists[0];
    }
};
