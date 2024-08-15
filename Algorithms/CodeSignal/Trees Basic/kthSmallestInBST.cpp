//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
void inorder(Tree<int>* t, int k, int& count, int& result)
{
    if(!t || count >= k)
    {
        return;
    } 
    inorder(t->left,k,count,result);   
    ++count;
    if(count == k)
    {
        result = t->value;
    }
    
    inorder(t->right,k,count,result);   
}

int solution(Tree<int>* t, int k) 
{
    int result = 0;
    int count = 0;
    
    inorder(t,k,count,result);
    return result;
}
