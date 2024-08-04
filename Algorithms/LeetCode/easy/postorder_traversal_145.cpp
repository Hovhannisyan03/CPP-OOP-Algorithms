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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(!root)
        {
            return {};
        }    
        stack<TreeNode*> s1;
        stack<int> s2;
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode* current = s1.top();
            s1.pop();

            s2.push(current->val);
            if(current->left)
            {
                s1.push(current->left);
            }
            if(current->right)
            {
                s1.push(current->right);
            }
        }
        vector<int> result;
        while(!s2.empty())
        {
            result.push_back(s2.top());
            s2.pop();
        }
        return result;
    }
};
