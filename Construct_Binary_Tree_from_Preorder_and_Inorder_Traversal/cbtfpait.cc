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

    TreeNode *recursiveBT(vector<int> &preorder, int startp, int endp,
                          vector<int> &inorder, int starti, int endi)
    {
        if(startp>endp)
            return NULL;
        else
        {
            int root_val = preorder[startp];
            TreeNode *root = new TreeNode(root_val); 
            int i = starti;
            while(inorder[i]!=root_val)
                i++;

            root->left = recursiveBT(preorder, startp+1, startp+i-starti, inorder, starti, i-1);
            root->right = recursiveBT(preorder, startp+i-starti+1, endp, inorder, i+1, endi);

            return root;
        }
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return recursiveBT(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);    
    }
};
