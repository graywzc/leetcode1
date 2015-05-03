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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;       
        if(root == NULL)
            return res;
        queue<TreeNode*> qu;
        qu.push(root);
        int flag = 0;

        while(!qu.empty())
        {
            int size = qu.size(); 
            vector<int> temp;
            while(size>0)
            {
                TreeNode *nd = qu.front();
                qu.pop();
                temp.push_back(nd->val);
                if(nd->left)
                    qu.push(nd->left);
                if(nd->right)
                    qu.push(nd->right);
                size--; 
            }
            if(flag)
                reverse(temp.begin(), temp.end()); 

            res.push_back(temp);
            flag = 1-flag;
        }

        return res;
    }
};
