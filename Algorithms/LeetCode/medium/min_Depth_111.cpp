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
    int minDepth(TreeNode* root) 
    {   
        if(!root)
        {
            return 0;
        }
        return get_Height(root);
    }

    int get_Height(TreeNode* node)
    {
        if(!node)
        {
            return INT_MAX;
        }
        
        if(!node->left && !node->right)
        {
            return 1;
        }
        
        int left = get_Height(node->left);
        int right = get_Height(node->right);

        return min(left,right) + 1;
    }
};
