#include "AVL.h"

template<typename T>
my_std::AVL<T>::Node::Node() : m_val{0}, m_left{nullptr}, m_right{nullptr} {}

template<typename T>
my_std::AVL<T>::Node::Node(value_type val) : m_val{val}, m_left{nullptr}, m_right{nullptr} {}

template<typename T>
my_std::AVL<T>::AVL() : m_root{nullptr}, m_size{0} {}

template <typename T>
my_std::AVL<T>::AVL(const_reference val) : m_root(new Node(val)), m_size{1} {}

template<typename T>
my_std::AVL<T>::AVL(const AVL& rhv) : m_root(m_copy_tree_recursive(rhv.m_root)), m_size{rhv.m_size}{}

template<typename T>
my_std::AVL<T>::AVL(std::initializer_list<value_type> init) : m_root(nullptr), m_size{init.size()}
{
    for(const auto& elem : init)
    {
        m_root = m_insert_recursive(m_root,elem);
    }
}

template<typename T>
my_std::AVL<T>::AVL(AVL&& rhv) noexcept : m_root(rhv.m_root), m_size{rhv.m_size}
{
    rhv.m_root = nullptr;
    rhv.m_size = 0;
}

template<typename T>
my_std::AVL<T>::~AVL()
{
    clear_recursive(m_root);
    m_root = nullptr;
}

template <typename T>
typename my_std::AVL<T>::AVL& my_std::AVL<T>::operator=(const AVL& rhv)
{
    if(this != &rhv)
    {
        clear_recursive(m_root);
        m_root = m_copy_tree_recursive(rhv.m_root);
        m_size = rhv.m_size;
    }
    return *this;
}

template <typename T>
typename my_std::AVL<T>::AVL& my_std::AVL<T>::operator=(AVL&& rhv) noexcept
{
    if(this != &rhv)
    {
        clear_recursive(m_root);
        m_root = rhv.m_root;
        m_size = rhv.m_size;
        rhv.m_root = nullptr;
        rhv.m_size = 0;
    }
    return *this;
}

template <typename T>
typename my_std::AVL<T>::AVL& my_std::AVL<T>::operator=(std::initializer_list<value_type> init)
{
    clear_recursive(m_root);
    m_root = nullptr;
    m_size = 0;
    for(const auto& elem : init)
    {
        m_root = m_insert_recursive(m_root,elem);
    }
    return *this;
}

template<typename T>
const typename my_std::AVL<T>::Node* my_std::AVL<T>::get_min() const
{
    return m_min_recursive(m_root);
}

template<typename T>
const typename my_std::AVL<T>::Node* my_std::AVL<T>::get_max() const
{
    return m_max_recursive(m_root);
}

template <typename T>
typename my_std::AVL<T>::size_type my_std::AVL<T>::get_height() const
{
    return m_height_recursive(m_root);
}

template <typename T>
void my_std::AVL<T>::remove(value_type val)
{
    m_root = m_remove_recursive(m_root,val);
}

template <typename T>
void my_std::AVL<T>::insert(value_type val)
{
    m_root = m_insert_recursive(m_root,val);
}

template <typename T>
void my_std::AVL<T>::inorder(predicate visit, bool iterative) const
{   
    if(!iterative)
    {
        m_inorder_recursive(m_root,visit);
    }
    else
    {
        m_inorder_iterative(m_root,visit);
    }
    std::cout << std::endl;
}

template <typename T>
void my_std::AVL<T>::preorder(predicate visit, bool iterative) const
{
    if(!iterative)
    {
        m_preorder_recursive(m_root,visit);
    }
    else
    {
        m_preorder_iterative(m_root,visit);
    }
    std::cout << std::endl;
}


template <typename T>
void my_std::AVL<T>::postorder(predicate visit, bool iterative) const
{
    if(!iterative)
    {
        m_postorder_recursive(m_root,visit);
    }
    else
    {
        m_postorder_iterative(m_root,visit);
    }
    std::cout << std::endl;
}

template<typename T>
typename my_std::AVL<T>::size_type my_std::AVL<T>::get_number_of_nodes() const
{
    return m_size;
}

template<typename T>
typename my_std::AVL<T>::Node* my_std::AVL<T>::get_Entry(value_type val) const
{
    Node* temp = m_get_Entry_recursive(m_root,val);
    if(temp)
    {
        return temp;
    }
    throw std::logic_error("Node with this value does not exist");
}

template <typename T>
bool my_std::AVL<T>::contains(value_type val) const
{
    if(m_get_Entry_recursive(m_root, val))
    {
        return true;
    }
    return false;
}

template <typename T>
void my_std::AVL<T>::level_order(predicate visit, bool recursive) const
{   
    if(!recursive)
    {
        m_level_order_iterative(m_root,visit);
    }
    else
    {
        if(!m_root)
        {
            return;
        }
        std::queue<Node*> q;
        q.push(m_root);
        m_level_order_recursive(q,visit);
    }
    std::cout << std::endl;
}

template<typename T>
typename my_std::AVL<T>::value_type my_std::AVL<T>::get_root_data() const
{
    if(m_root)
    {
        return m_root->m_val;
    }
    throw std::logic_error("BST is empty");
}

template<typename T>
void my_std::AVL<T>::clear_recursive(Node* node)
{
    if(node)
    {
       clear_recursive(node->m_left);
       clear_recursive(node->m_right);
       --m_size;
       delete node; 
    }
}

template<typename T>
void my_std::AVL<T>::clear_iterative(Node* node)
{
    if(!node)
    {
        return;
    }
    std::stack<Node*> s1;
    s1.push(node);
    while(!s1.empty())
    {
        Node* temp = s1.top();
        s1.pop();

        if(temp->m_left)
        {
            s1.push(temp->m_left);
        }
        if(temp->m_right)
        {
            s1.push(temp->m_right);
        }
        delete temp;
    }
    m_size = 0;
}

template<typename T>
typename my_std::AVL<T>::Node* my_std::AVL<T>::m_copy_tree_recursive(Node* node)
{
    if(!node)
    {
        return nullptr;
    }
    Node* newNode = new Node(node->m_val);
    newNode->m_left = m_copy_tree_recursive(node->m_left);
    newNode->m_right = m_copy_tree_recursive(node->m_right);
    return newNode;
}

template <typename T>
typename my_std::AVL<T>::Node* my_std::AVL<T>::m_min_recursive(Node* node)const
{
    if(!node)
    {
        return nullptr;
    }
    if(node->m_left)
    {
        return m_min_recursive(node->m_left);
    }
    return node;
}

template <typename T>
typename my_std::AVL<T>::Node* my_std::AVL<T>::m_min_iterative(Node* node)const
{
    if(!node)
    {
        return nullptr;
    }
    while(node->m_left)
    {
        node = node->m_left;
    }
    return node;
}

template <typename T>
typename my_std::AVL<T>::Node* my_std::AVL<T>::m_max_recursive(Node* node)const
{
    if(!node)
    {
        return nullptr;
    }
    else if(node->m_right)
    {
        return m_max_recursive(node->m_right);
    }
    
    return node;
}

template <typename T>
typename my_std::AVL<T>::Node* my_std::AVL<T>::m_max_iterative(Node* node)const
{
    if(!node)
    {
        return nullptr;
    }
    while(node->m_right)
    {
        node = node->m_right;
    }
    return node;
}

template <typename T>
typename my_std::AVL<T>::size_type my_std::AVL<T>::m_height_recursive(Node* node) const
{
    if(!node)
    {
        return 0;
    }
    int left = m_height_recursive(node->m_left);
    int right = m_height_recursive(node->m_right);
    return std::max(left,right) + 1;
}

template <typename T>
typename my_std::AVL<T>::size_type my_std::AVL<T>::m_height_iterative(Node* node) const
{
    if(!node)
    {
        return 0;
    }
    size_type height = 0;
    std::queue<Node*> q;
    q.push(node);
    while(!q.empty())
    {
        size_type level = q.size();
        for(size_type i = 0; i < level; ++i)
        {
            Node* temp = q.front();
            q.pop();
            
            if(temp->m_left)
            {
                q.push(temp->m_left);
            }
            if(temp->m_right)
            {
                q.push(temp->m_right);
            }
        }
        ++height;
    }
    return height;
}

template <typename T>
typename my_std::AVL<T>::Node* my_std::AVL<T>::m_insert_recursive(Node* node, value_type val)
{
    if(!node)
    {
        ++m_size;
        node = new Node(val);
    }
    else if(node->m_val > val)
    {
        node->m_left = m_insert_recursive(node->m_left, val);
    }
    else if(node->m_val < val)
    {
        node->m_right = m_insert_recursive(node->m_right, val);
    }
    else
    {
        return node;
    }

    int bf = m_balance_factor(node);
    if(bf > 1 && val < node->m_left->m_val)
    {
        return rightRotate(node);
    }
    if(bf > 1 && val > node->m_left->m_val)
    {   
        node->m_left = leftRotate(node->m_left);
        return rightRotate(node);
    }
    if(bf < -1 && val > node->m_right->m_val)
    {
        return leftRotate(node);
    }
    if(bf < -1 && val < node->m_right->m_val)
    {
        node->m_right = rightRotate(node->m_right);
        return leftRotate(node);
    }
    return node;
}

template <typename T>
typename my_std::AVL<T>::Node* my_std::AVL<T>::m_insert_iterative(Node* node, value_type val)
{
    if(!node)
    {
        ++m_size;
        return new Node(val);
    }
    Node* temp = node;
    while(temp)
    {
        if(temp->m_val > val)
        {
            if(!temp->m_left)
            {
                temp->m_left = new Node(val);
                ++m_size;
                return node;
            }
            temp = temp->m_left;
        }
        else if(temp->m_val < val)
        {
            if(!temp->m_right)
            {
                temp->m_right = new Node(val);
                ++m_size;
                return node;
            }
            temp = temp->m_right;
        }
        else
        {
            break;
        }
    }

    int bf = m_balance_factor(node);
    if(bf > 1 && val < node->m_left->m_val)
    {
        return rightRotate(node);
    }
    if(bf > 1 && val > node->m_left->m_val)
    {   
        node->m_left = leftRotate(node->m_left);
        return rightRotate(node);
    }
    if(bf < -1 && val > node->m_right->m_val)
    {
        return leftRotate(node);
    }
    if(bf < -1 && val < node->m_right->m_val)
    {
        node->m_right = rightRotate(node->m_right);
        return leftRotate(node);
    }
    return node;
}

template <typename T>
typename my_std::AVL<T>::Node* my_std::AVL<T>::m_remove_recursive(Node* node, value_type val)
{
    if(!node)
    {
        return nullptr;
    }
    if(node->m_val > val)
    {
        node->m_left = m_remove_recursive(node->m_left, val);
    }
    else if(node->m_val < val)
    {
        node->m_right = m_remove_recursive(node->m_right,val);
    }
    else
    {
        if(!node->m_left)
        {
            Node* del = node;
            node = node->m_right;
            delete del;
            --m_size;
        }
        else if(!node->m_right)
        {   
            Node* del = node;
            node = node->m_left;
            delete del;
            --m_size;
        }
        else
        {
            Node* temp = m_min_recursive(node->m_right);
            node->m_val = temp->m_val;
            node->m_right = m_remove_recursive(node->m_right,temp->m_val);
            --m_size;        
        }
    }
    if(!node)
    {
        return node;
    }
    int bf = m_balance_factor(node);

    if (bf > 1 && m_balance_factor(node->m_left) >= 0)
    {
        return rightRotate(node); 
    }
    if (bf > 1 && m_balance_factor(node->m_left) < 0)
    {
        node->m_left = leftRotate(node->m_left);
        return rightRotate(node);
    }
    if (bf < -1 && m_balance_factor(node->m_right) <= 0)
    {
        return leftRotate(node); 
    }
    if (bf < -1 && m_balance_factor(node->m_right) > 0)
    {
        node->m_right = rightRotate(node->m_right); 
        return leftRotate(node);
    }
    return node;
}


template <typename T>
void my_std::AVL<T>::m_inorder_recursive(Node* node, predicate visit) const
{   
    if(!node)
    {
        return;
    }
    m_inorder_recursive(node->m_left,visit);
    visit(node->m_val);
    m_inorder_recursive(node->m_right,visit);
}

template <typename T>
void my_std::AVL<T>::m_inorder_iterative(Node* node, predicate visit) const
{   
    if(!node)
    {
        return;
    }
    std::stack<Node*> st;
    while(node || !st.empty())
    {
        while(node)
        {
            st.push(node);
            node = node->m_left;
        }
        node = st.top();
        visit(node->m_val);
        st.pop();
        node = node->m_right;
    }
}


template <typename T>
void my_std::AVL<T>::m_preorder_recursive(Node* node, predicate visit) const
{   
    if(!node)
    {
        return;
    }
    visit(node->m_val);
    m_preorder_recursive(node->m_left,visit);
    m_preorder_recursive(node->m_right,visit);
}


template <typename T>
void my_std::AVL<T>::m_preorder_iterative(Node* node, predicate visit) const
{   
    if(!node)
    {
        return;
    }
    std::stack<Node*> s;
    s.push(node);
    while(!s.empty())
    {
        Node* temp = s.top();
        s.pop();

        visit(temp->m_val);
        if(temp->m_right)
        {
            s.push(temp->m_right);
        }
        if(temp->m_left)
        {
            s.push(temp->m_left);
        }
    }
}

template <typename T>
void my_std::AVL<T>::m_postorder_recursive(Node* node, predicate visit) const
{   
    if(!node)
    {
        return;
    }
    m_postorder_recursive(node->m_left,visit);
    m_postorder_recursive(node->m_right,visit);
    visit(node->m_val);
}

template <typename T>
void my_std::AVL<T>::m_postorder_iterative(Node* node, predicate visit) const
{   
    if(!node)
    {
        return;
    }
    std::stack<Node*> s1;
    std::stack<int> s2;
    s1.push(node);
    while(!s1.empty())
    {
        Node* temp = s1.top();
        s1.pop();

        s2.push(temp->m_val);
        if(temp->m_left)
        {
            s1.push(temp->m_left);
        }
        if(temp->m_right)
        {
            s1.push(temp->m_right);
        }
    }

    while(!s2.empty())
    {
        visit(s2.top());
        s2.pop();
    }
}


template <typename T>
void my_std::AVL<T>::m_level_order_iterative(Node* node, predicate visit) const
{                   
    if(!node)
    {
        return;
    }
    std::queue<Node*> q;
    q.push(node);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        
        visit(temp->m_val);
        if(temp->m_left)
        {
            q.push(temp->m_left);
        }
        if(temp->m_right)
        {
            q.push(temp->m_right);
        }
    }
    std::cout << std::endl;
}

template <typename T>
void my_std::AVL<T>::m_level_order_recursive(std::queue<Node*>& q, predicate visit) const
{
    if(q.empty())
    {
        return;
    }
    Node* current = q.front();
    q.pop();
    visit(current->m_val);
    if(current->m_left)
    {
        q.push(current->m_left);
    }
    if(current->m_right)
    {
        q.push(current->m_right);
    }
    m_level_order_recursive(q,visit);
}


template <typename T>
typename my_std::AVL<T>::Node* my_std::AVL<T>::m_get_Entry_recursive(Node* node, value_type val) const
{
    if (!node)
    {
        return nullptr;
    }
    else if (node->m_val > val)
    {
        return m_get_Entry_recursive(node->m_left, val);
    }
    else if (node->m_val < val)
    {
        return m_get_Entry_recursive(node->m_right, val);
    }
    else
    {
        return node;
    }
}

template <typename T>
typename my_std::AVL<T>::Node* my_std::AVL<T>::m_get_Entry_iterative(Node* node, value_type val) const
{
    if(node)
    {
        Node* temp = node;
        while(temp)
        {
            if(temp->m_val > val)
            {
                temp = temp->m_left;
            }
            else if(temp->m_val < val)
            {
                temp = temp->m_right;
            }
            else
            {
                return temp;
            }
        }
    }
    return nullptr;
}

template <typename T>
typename my_std::AVL<T>::Node* my_std::AVL<T>::get_successor(Node* node) const
{
    if(!node)
    {
        return nullptr;
    }
    if(node->m_right)
    {
        return m_min_recursive(node->m_right);
    }
    Node* successor = nullptr;
    Node* ancestor = m_root;
    while(ancestor != node)
    {
        if(ancestor->m_val > node->m_val)
        {
            successor = ancestor;
            ancestor = ancestor->m_left;
        }
        else
        {
            ancestor = ancestor->m_right;
        }
    }
    return successor;
}

template <typename T>
typename my_std::AVL<T>::Node* my_std::AVL<T>::get_predecessor(Node* node) const
{
    if(!node)
    {
        return nullptr;
    }
    if(node->m_left)
    {
        return m_max_recursive(node->m_left);
    }
    Node* predecessor = nullptr;
    Node* ancestor = m_root;
    while(ancestor != node)
    {
        if(ancestor->m_val < node->m_val)
        {
            predecessor = ancestor;
            ancestor = ancestor->m_right;
        }
        else
        {
            ancestor = ancestor->m_left;
        }
    }
    return predecessor;
}

template <typename T>
typename my_std::AVL<T>::Node* my_std::AVL<T>::leftRotate(Node* node)
{
    Node* temp = node->m_right;  
    Node* tempLeft = temp->m_left; 

    temp->m_left = node;
    node->m_right = tempLeft;

    return temp;

}

template <typename T>
typename my_std::AVL<T>::Node* my_std::AVL<T>::rightRotate(Node* node)
{
    Node* temp = node->m_left; 
    Node* tempRight = temp->m_right;

    temp->m_right = node;
    node->m_left = tempRight;

    return temp;
}

template <typename T>
int my_std::AVL<T>::m_balance_factor(Node* node)
{
    return m_height_recursive(node->m_left) - m_height_recursive(node->m_right);
}


