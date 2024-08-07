/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {   
        if(!root)
        {
            return false;
        }
        int val = 0;
        bool flag = false;
        stack<TreeNode*> s;
        TreeNode* current = root;
        while(current || !s.empty())
        {
            while(current)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            if(!flag)
            {
                val = current->val;
                flag = true;
            }
            else if(val < current->val)
            {
                val = current->val;
            }
            else
            {
                return false;
            }
            current = current->right;
        }
        return true;
    }
};
