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
        if(root == NULL)
            return;
        TreeLinkNode *left = root->left;
        TreeLinkNode *right = root->right;
        if(left)
        {
            connect(left); 
            connect(right);
        }
        while(left)
        {
            left->next = right; 
            left = left->right;
            right = right->left;
        }
    }
};
