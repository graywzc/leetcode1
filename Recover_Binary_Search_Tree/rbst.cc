/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void findReverse(TreeNode *node, int& prev_val, TreeNode **prev_node, TreeNode **swap_node1, TreeNode **swap_node2)
    {
        if(node->left!=NULL)     
            findReverse(node->left, prev_val, prev_node, swap_node1, swap_node2);
        
        if(node->val<prev_val)
        {
            if(*swap_node1 == NULL) 
            {
                *swap_node1 = *prev_node; 
                *swap_node2 = node;
            }
            else
            {
                *swap_node2 = node; 
            }
        }
        else if(node->val == prev_val && prev_val == (*swap_node2)->val) 
            *swap_node2 = node;

        *prev_node = node;
        prev_val = node->val;
        if(node->right!=NULL)
            findReverse(node->right, prev_val, prev_node, swap_node1, swap_node2);
    }

    void recoverTree(TreeNode *root) {
        assert(root);          
        int prev_val = INT_MIN;
        TreeNode *prev_node = NULL;
        TreeNode *swap_node1 = NULL;
        TreeNode *swap_node2 = NULL;
        findReverse(root, prev_val, &prev_node, &swap_node1, &swap_node2);
        int temp = swap_node1->val;
        swap_node1->val = swap_node2->val;
        swap_node2->val = temp;
    }
};
