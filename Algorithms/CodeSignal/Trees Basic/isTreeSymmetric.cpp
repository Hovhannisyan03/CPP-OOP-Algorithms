//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };


bool isSame(Tree<int>* left, Tree<int>* right)
{
    if(!left || !right)
    {
        return left == right;
    }
    
    return (left->value == right->value) && isSame(left->left, right->right) && isSame(left->right, right->left);
}

bool solution(Tree<int> * t) 
{
   if(!t)
   {
       return true;
   } 
   return isSame(t->left, t->right);
}

