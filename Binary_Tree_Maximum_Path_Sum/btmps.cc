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
    void maxPathSum(TreeNode *root, int &mps, int &rps)
    {
        if(root->left == NULL && root->right == NULL)
        {
            rps = mps = root->val; 
        }
        else if(root->left == NULL)
        {
            int right_rps, right_mps; 
            maxPathSum(root->right, right_mps, right_rps);
            mps = max(right_mps, root->val+(right_rps>0?right_rps:0));
            rps = root->val + (right_rps>0?right_rps:0);
        }
        else if(root->right == NULL)
        {
            int left_rps, left_mps; 
            maxPathSum(root->left, left_mps, left_rps);
            mps = max(left_mps, root->val+(left_rps>0?left_rps:0));
            rps = root->val + (left_rps>0?left_rps:0);
        }
        else
        {
            int left_rps, left_mps, right_rps, right_mps; 
            maxPathSum(root->right, right_mps, right_rps);
            maxPathSum(root->left, left_mps, left_rps);
            mps = max(left_mps, right_mps);
            mps = max(mps, root->val+(left_rps>0?left_rps:0)+(right_rps>0?right_rps:0));
            int temp = max(left_rps, right_rps);
            rps = root->val + (temp>0?temp:0);
        }
    }
    int maxPathSum(TreeNode *root) {
        if(root==NULL)
            return 0;
        
        int mps, rps;
        maxPathSum(root, mps, rps);
        return mps; 
    }
};
