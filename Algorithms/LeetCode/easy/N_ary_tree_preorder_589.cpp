/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) 
    {
        vector<int> result;
        helper(root, result);
        return result;   
    }

    void helper(Node* node, vector<int>& vec)
    {
        if(!node)
        {
            return;
        }
        vec.push_back(node->val);
        for(auto& elem : node->children)
        {
            helper(elem, vec);
        }
    }
};
