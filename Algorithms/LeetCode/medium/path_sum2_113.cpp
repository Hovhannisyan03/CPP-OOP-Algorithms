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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        helper(root,0,targetSum,path,result); 
        return result;  
    }

    void helper(TreeNode* node, int curr_sum, int targetSum, std::vector<int>& path, std::vector<std::vector<int>>& result)
    {
        if(!node)
        {
            return;
        }
        path.push_back(node->val);
        curr_sum += node->val;

        if (!node->left && !node->right && curr_sum == targetSum) 
        {
            result.push_back(path);
        } 
        else 
        {
            helper(node->left, curr_sum, targetSum, path, result);
            helper(node->right, curr_sum, targetSum, path, result);
        }

        path.pop_back();
    }


};
