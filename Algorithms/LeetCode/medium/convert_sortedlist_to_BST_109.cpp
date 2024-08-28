/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) 
    {   
        TreeNode* root = nullptr;
        while(head)
        {
            root = insert(root,head->val);
            head = head->next;
        }
        return root;
    }

    TreeNode* insert(TreeNode* root, int val)
    {
        if(!root)
        {
            return new TreeNode(val);
        }
        else if(root->val > val)
        {
            root->left = insert(root->left, val);
        }
        else if(root->val < val)
        {
            root->right = insert(root->right, val);
        }
        else
        {
            return root;
        }

        int bs = getHeight(root->left) - getHeight(root->right);
        if(bs > 1 && val < root->left->val)
        {
            return rightRotate(root);
        }
        if(bs > 1 && val > root->left->val)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if(bs < -1 && val > root->right->val)
        {
            return leftRotate(root);
        }
        if(bs < -1 && val < root->left->val)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    int getHeight(TreeNode* node)
    {
        if(!node)
        {
            return 0;
        }
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        return max(left,right) + 1;
    }

    TreeNode* leftRotate(TreeNode* node)
    {
        TreeNode* temp = node->right;

        node->right = temp->left;
        temp->left = node;
        return temp;
    }

    TreeNode* rightRotate(TreeNode* node)
    {
        TreeNode* temp = node->left;

        node->left = temp->right;
        temp->right = node;
        return temp;
    }
};
