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
class Solution 
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {   
        return divide(nums,0,nums.size(),root);
    }

    TreeNode* divide(vector<int>& nums, int f, int l,TreeNode* root)
    {   
        if(f < l)
        {   
            int mid = f + (l - f) / 2;
            root = insert(root, nums[mid]);
            divide(nums,f,mid,root);
            divide(nums,mid+1,l,root);
        }
        return root;
    }

    TreeNode* insert(TreeNode* root, int val)
    {
        if(!root)
        {
            return new TreeNode(val);
        }
        if(root->val > val)
        {
            root->left = insert(root->left, val);
        }
        else if(root->val < val)
        {
            root->right = insert(root->right, val);
        }
        return root;
    }
};
