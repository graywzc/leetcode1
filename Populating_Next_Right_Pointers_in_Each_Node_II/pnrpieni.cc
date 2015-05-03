/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *cur = root; 
        TreeLinkNode *head = NULL;
        TreeLinkNode *last = NULL;
        
        while(1)
        {
            while(cur)
            {
                if(cur->left)
                {
                    if(last == NULL) 
                    {
                        last = cur->left; 
                        head = cur->left;
                    }
                    else
                    {
                        last->next = cur->left;  
                        last = cur->left;
                    }
                }
                if(cur->right)
                {
                    if(last == NULL) 
                    {
                        head = cur->right;
                        last = cur->right;
                    }
                    else
                    {
                        last->next = cur->right;
                        last = cur->right;
                    }
                }
                cur = cur->next; 
            }
            cur = head;
            if(cur==NULL)
                break;
            head = NULL;
            last = NULL;
        }
    }
};
