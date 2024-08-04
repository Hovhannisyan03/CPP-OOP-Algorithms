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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(!root)
        {
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> result;
        vector<int> row;
        q.push(root);
        while(!q.empty())
        {   
            int level = q.size();
            for(int i = 0; i < level; ++i)
            {
                TreeNode* current = q.front();
                q.pop();
                row.push_back(current->val);
                if(current->left)
                {
                    q.push(current->left);
                }
                if(current->right)
                {
                    q.push(current->right);
                }
            }
            result.push_back(row);
            row.clear();
        }
        return result;
    }
};
