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
    int sumRootToLeaf(TreeNode* root) 
    {
        int result = 0;
        helper(root,0,result);
        return result;
    }

    void helper(TreeNode* node, int current, int& result)
    {
        if(!node)
        {
            return;
        }
        current = (current << 1) + node->val;
        if(!node->left && !node->right)
        {
            result += current;
        }
        helper(node->left, current, result);
        helper(node->right, current, result);

    }
};
