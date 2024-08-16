//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };


int findIndex(vector<int>& inorder, int key)
{
    int i = 0;
    for(i = 0; i < inorder.size(); ++i)
    {
        if(inorder[i] == key)
        {
            break;
        }
    }    
    return i;
}

Tree<int>* restore(vector<int>& inorder, vector<int>& preorder, int in_f, int in_l, int& preIndex)
{
    if(in_f > in_l)
    {
        return nullptr;
    }   
    
    int rootVal = preorder[preIndex++];
    Tree<int>* root = new Tree(rootVal);
    
    int inIndex = findIndex(inorder,rootVal);
    
    root->left = restore(inorder, preorder, in_f, inIndex - 1, preIndex);
     root->right = restore(inorder, preorder, inIndex + 1, in_l, preIndex);
    return root;
}

Tree<int>* solution(vector<int>& inorder, vector<int>& preorder) 
{
    int preIndex = 0;
    return restore(inorder,preorder,0,inorder.size() - 1, preIndex);
}

