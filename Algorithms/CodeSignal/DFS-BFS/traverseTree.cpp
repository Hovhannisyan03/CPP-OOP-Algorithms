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
    vector<int> result;
    queue<Tree<int>*> q;
    q.push(t);
    while(!q.empty())
    {
        int level = q.size();
        for(int i = 0; i < level; ++i)
        {
            Tree<int>* temp = q.front();
            result.push_back(temp->value);
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return result;
    
}

