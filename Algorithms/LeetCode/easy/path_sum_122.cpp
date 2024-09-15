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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        bool has = false;
        helper(root, 0, has, targetSum);
        return has;    
    }

    void helper(TreeNode* node, int curr_sum, bool& has, int targetSum)
    {
        if(!node)
        {
            return;
        }
        if(!node->left && !node->right && (curr_sum + node->val == targetSum))
        {
            has = true;
            return;
        }
        curr_sum += node->val;
        helper(node->left, curr_sum, has, targetSum);
        helper(node->right, curr_sum, has, targetSum);
    }
};
