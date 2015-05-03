/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)        
            return NULL;

        RandomListNode *p1 = head;
        RandomListNode *p2;
        while(p1)
        {
            p2 = p1->next;     
            p1->next = new RandomListNode(p1->label);
            p1->next->next = p2;
            p1 = p2;
        }

        p1 = head;
        while(p1)
        {
            p1->next->random = p1->random?p1->random->next:NULL; 
            p1 = p1->next->next;
        }
        p1 = head;
        RandomListNode *res = p1->next;
        p2 = res;
        while(p1) 
        {
            p1->next = p2->next;     
            p1 = p1->next;
            p2->next = p1?p1->next:NULL;
            p2 = p2->next;
        }

        return res;
    }
};
