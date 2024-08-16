Tree<int>* findMax(Tree<int>* root)
{
    if(!root)
    {
        return nullptr;
    }
    if(root->right)
    {
        root = findMax(root->right);
    }
    return root;
}

Tree<int>* removeRightmost(Tree<int>* root) 
{
    if (!root->right) 
    {
        Tree<int>* leftChild = root->left;
        delete root;
        return leftChild;
    }
    root->right = removeRightmost(root->right);
    return root;
}

Tree<int>* removeNode(Tree<int>* root, int val) 
{
    if (!root) 
    {
        return nullptr;
    }

    if (val < root->value) 
    {
        root->left = removeNode(root->left, val);
    } 
    else if (val > root->value) 
    {
        root->right = removeNode(root->right, val);
    } 
    else 
    {
        if (root->left) 
        {
            Tree<int>* rightmost = findMax(root->left);
            root->value = rightmost->value;
            root->left = removeRightmost(root->left);
        } 
        else 
        {
            Tree<int>* rightChild = root->right;
            delete root;
            return rightChild;
        }
    }
    return root;
}

Tree<int>* solution(Tree<int> *t, vector<int> queries) 
{
    for(int elem : queries)
    {
        t = removeNode(t,elem);
    }
    return t;
}
