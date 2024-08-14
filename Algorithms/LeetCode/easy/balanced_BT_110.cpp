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
    bool isBalanced(TreeNode* root) 
    {
        return height(root) != -1;
    }

private:
    int height(TreeNode* node)
    {
        if(!node)
        {
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
        if(right == -1 || left == -1 || abs(left - right) > 1)
        {
            return -1;
        }
        return std::max(left,right) + 1;
    }
};
