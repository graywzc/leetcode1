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
    vector<int> inorderTraversal(TreeNode *root) {

        vector<int> res;
        TreeNode *cur = root;
        stack<TreeNode*> st;
        
        while(cur || !st.empty())
        {
            if(cur)
            {
                st.push(cur); 
                cur = cur->left;
            }
            else
            {
                cur = st.top(); 
                st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }

        return res;
    }
};
