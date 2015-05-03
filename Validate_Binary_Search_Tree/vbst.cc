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
    bool isValidBST(TreeNode *node, int &max, int &min)
    {
        if(node->left == NULL && node->right == NULL) 
        {
            max = min = node->val; 
            return true;
        }
        else if(node->left == NULL)
        {
            if(isValidBST(node->right, max, min) && node->val<min)     
            {
                min = node->val;     
                return true;
            }
            else
                return false;
        }
        else if(node->right == NULL)
        {
            if(isValidBST(node->left, max, min) && node->val>max) 
            {
                max = node->val; 
                return true;
            }
            else
                return false;
        }
        else
        {
            int lmax,lmin,rmax,rmin; 
            if(isValidBST(node->left,lmax,lmin) && isValidBST(node->right,rmax,rmin) && lmax<node->val && node->val<rmin)
            {
                min = lmin;
                max = rmax;
                return true;
            }
            else
                return false;
        }
    }

    bool isValidBST(TreeNode *root) {
        if(root == NULL)                    
            return true;

        int min, max;
        return isValidBST(root, max, min);

    }
};
