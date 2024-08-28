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
   TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int> vec;
        inorder(root, vec);
        return sortedArrayToBST(vec, 0, vec.size() - 1);
    }

private:
    void inorder(TreeNode* node, vector<int>& vec) 
    {
        if (!node) return;
        inorder(node->left, vec);
        vec.push_back(node->val);
        inorder(node->right, vec);
    }

    TreeNode* sortedArrayToBST(const vector<int>& vec, int start, int end) 
    {
        if (start > end) 
        {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = sortedArrayToBST(vec, start, mid - 1);
        root->right = sortedArrayToBST(vec, mid + 1, end);
        
        return root;
    }
};
