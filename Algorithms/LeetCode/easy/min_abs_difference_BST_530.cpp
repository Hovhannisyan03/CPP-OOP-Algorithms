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
    int getMinimumDifference(TreeNode* root) 
    {   
        int difference = INT_MAX;
        int prev = -1;
        helper(root, difference, prev);
        return difference;
    }

    void helper(TreeNode* node, int& difference, int &prev)
    {
        if(!node)
        {
            return;
        }
        helper(node->left,difference,prev);
        if(prev != -1)
        {
            difference = min(difference, node->val - prev);
        }
        prev = node->val;
        helper(node->right,difference,prev);

    }
};
