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

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *cur = root;
        stack<TreeNode*> st;

        while(cur || !st.empty())
        {
            if(cur) 
            {
                res.push_back(cur->val); 
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top(); 
                st.pop();
                cur = cur->right;
            }
        }

        return res;

    }
};
