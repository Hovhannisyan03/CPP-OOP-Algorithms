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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        std::vector<string> result;
        helper(root,"",result);
        return result;
    }

    void helper(TreeNode* node, std::string current, std::vector<string>& result)
    {
        if(!node)
        {
            return;
        }

        if(!node->left && !node->right)
        {
            current += std::to_string(node->val);
            result.push_back(current);
            return;
        }
        current += std::to_string(node->val);
        current += "->";
        helper(node->left, current, result);
        helper(node->right, current, result);
    }
};
