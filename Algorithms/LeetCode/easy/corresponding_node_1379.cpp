/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        TreeNode* copy_target = nullptr;
        helper(original, cloned, target, copy_target);
        return copy_target;
    }

    void helper(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode*& copy_target)
    {
        if(!original)
        {
            return;
        }

        if(original->val == target->val)
        {
            copy_target = cloned;
        }
        helper(original->left, cloned->left, target, copy_target);
        helper(original->right, cloned->right, target, copy_target);
    }
};
