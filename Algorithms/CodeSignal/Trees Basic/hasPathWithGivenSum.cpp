//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool solution(Tree<int> * t, int s) 
{
    if(!t)
    {
        return false;
    }
    if(!t->left && !t->right)
    {
        return s - t->value == 0;
    }

    return solution(t->left,s - t->value) || solution(t->right,s - t->value);
}
