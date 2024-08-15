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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(!root)
        {
            return false;
        } 
        
        return isSame(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSame(TreeNode* l, TreeNode* r)
    {
        if(!l || !r)
        {
            return l == r;
        }
        if(l->val != r->val)
        {
            return false;
        }
        return isSame(l->left, r->left) && isSame(l->right, r->right);
    }
};
