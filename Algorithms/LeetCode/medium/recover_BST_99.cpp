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
    void recoverTree(TreeNode* root) 
    {   
        if(!root)
        {
            return;
        }
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        helper(root, first, second, prev);

        if(first && second)
        {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }

    void helper(TreeNode* node, TreeNode*& first, TreeNode*& second, TreeNode*& prev)
    {
        if(!node)
        {
            return;
        }
        helper(node->left, first, second, prev);
        if(prev && node->val < prev->val)
        {
            if(!first)
            {
                first = prev;
            }
            second = node;
        }
        prev = node;
        helper(node->right, first, second, prev);
    }

};
