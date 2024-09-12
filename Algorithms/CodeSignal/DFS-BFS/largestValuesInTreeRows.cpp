//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
vector<int> solution(Tree<int> * t) 
{
    if(!t)
    {
        return {};
    }
    queue<Tree<int>*> q;
    vector<int> result;
    q.push(t);
    while(!q.empty())
    {
        int level = q.size();
        Tree<int>* temp = q.front();
        int max = temp->value;
        for(int i = 0; i < level; ++i)
        {
            temp = q.front();
            q.pop();
            if(max < temp->value)
            {
                max = temp->value;
            }
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        
        result.push_back(max);
    }
    return result;
}

