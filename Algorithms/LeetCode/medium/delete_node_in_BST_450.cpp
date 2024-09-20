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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root)
        {
            return root;
        }    
        else if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if(!root->left)
            {
                TreeNode* del = root;
                root = root->right;
                delete del;
                return root;
            }
            else if(!root->right)
            {
                TreeNode* del = root;
                root = root->left;
                delete del;
                return root;
            }
            else
            {
                TreeNode* successor = getMin(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }

    TreeNode* getMin(TreeNode* node)
    {
        while(node && node->left)
        {
            node = node->left;
        }
        return node;
    }
};
