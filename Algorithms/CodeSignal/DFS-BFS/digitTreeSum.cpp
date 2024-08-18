//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

long long sum(Tree<int>* t, long long res)
{
    if(!t)
    {
        return 0;
    }
    
    res = res * 10 + t->value;
    
    if(!t->left && !t->right)
    {
        return res;
    }
    
    return sum(t->left, res) + sum(t->right, res);
}

long long solution(Tree<int>* t) 
{   
    return sum(t,0);
}

