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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;        
        TreeNode *cur = root;
        TreeNode *prev = NULL;
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
                if(cur->right && prev!=cur->right) 
                {
                    cur = cur->right; 
                }
                else
                {
                    st.pop(); 
                    res.push_back(cur->val);
                    prev = cur;
                    cur = NULL;
                }
            }
        }

        return res;
    }
        
};
