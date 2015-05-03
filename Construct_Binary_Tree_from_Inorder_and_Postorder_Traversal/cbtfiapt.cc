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
    TreeNode *recursiveBT(vector<int> &inorder, int starti, int endi,
                          vector<int> &postorder, int startp, int endp)
    {
        if(starti>endi)     
            return NULL;
        else
        {
            int root_val = postorder[endp]; 
            TreeNode *root = new TreeNode(root_val);
            int i = starti;
            while(inorder[i]!=root_val)
                i++;

            root->left = recursiveBT(inorder, starti, i-1, postorder, startp, startp + i-1-starti); 
            root->right = recursiveBT(inorder, i+1, endi, postorder, startp+i-starti, endp-1);

            return root;
        }
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return recursiveBT(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);            
    }
};
