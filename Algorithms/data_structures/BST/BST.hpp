#include "BST.h"

template<typename T>
my_std::binary_search_tree<T>::Node::Node() : m_val{0}, m_left{nullptr}, m_right{nullptr} {}

template<typename T>
my_std::binary_search_tree<T>::Node::Node(value_type val) : m_val{val}, m_left{nullptr}, m_right{nullptr} {}

template<typename T>
my_std::binary_search_tree<T>::binary_search_tree() : m_root{nullptr}, m_size{0} {}

template <typename T>
my_std::binary_search_tree<T>::binary_search_tree(const_reference val) : m_root(new Node(val)), m_size{1} {}

template<typename T>
my_std::binary_search_tree<T>::binary_search_tree(const binary_search_tree& rhv) : m_root(m_copy_tree_recursive(rhv.m_root)), m_size{rhv.m_size}{}

template<typename T>
my_std::binary_search_tree<T>::binary_search_tree(std::initializer_list<value_type> init) : m_root(nullptr), m_size{init.size()}
{
    for(const auto& elem : init)
    {
        m_root = m_insert_recursive(m_root,elem);
    }
}

template<typename T>
my_std::binary_search_tree<T>::binary_search_tree(binary_search_tree&& rhv) noexcept : m_root(rhv.m_root), m_size{rhv.m_size}
{
    rhv.m_root = nullptr;
    rhv.m_size = 0;
}

template<typename T>
my_std::binary_search_tree<T>::~binary_search_tree()
{
    clear_recursive(m_root);
    m_root = nullptr;
}

template <typename T>
typename my_std::binary_search_tree<T>::binary_search_tree& my_std::binary_search_tree<T>::operator=(const binary_search_tree& rhv)
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
typename my_std::binary_search_tree<T>::binary_search_tree& my_std::binary_search_tree<T>::operator=(binary_search_tree&& rhv) noexcept
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
typename my_std::binary_search_tree<T>::binary_search_tree& my_std::binary_search_tree<T>::operator=(std::initializer_list<value_type> init)
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
const typename my_std::binary_search_tree<T>::Node* my_std::binary_search_tree<T>::get_min() const
{
    return m_min_recursive(m_root);
}

template<typename T>
const typename my_std::binary_search_tree<T>::Node* my_std::binary_search_tree<T>::get_max() const
{
    return m_max_recursive(m_root);
}

template <typename T>
typename my_std::binary_search_tree<T>::size_type my_std::binary_search_tree<T>::get_height() const
{
    return m_height_recursive(m_root);
}

template <typename T>
void my_std::binary_search_tree<T>::remove(value_type val)
{
    m_root = m_remove_iterative(m_root,val);
}

template <typename T>
void my_std::binary_search_tree<T>::insert(value_type val)
{
    m_root = m_insert_recursive(m_root,val);
}

template <typename T>
void my_std::binary_search_tree<T>::inorder(predicate visit, bool iterative) const
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
void my_std::binary_search_tree<T>::preorder(predicate visit, bool iterative) const
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
void my_std::binary_search_tree<T>::postorder(predicate visit, bool iterative) const
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
typename my_std::binary_search_tree<T>::size_type my_std::binary_search_tree<T>::get_number_of_nodes() const
{
    return m_size;
}

template<typename T>
typename my_std::binary_search_tree<T>::value_type my_std::binary_search_tree<T>::get_Entry(value_type val) const
{
    Node* temp = m_get_Entry_recursive(m_root,val);
    if(temp)
    {
        return temp->m_val;
    }
    throw std::logic_error("Node with this value does not exist");
}

template <typename T>
bool my_std::binary_search_tree<T>::contains(value_type val) const
{
    if(m_get_Entry_recursive(m_root, val))
    {
        return true;
    }
    return false;
}

template <typename T>
void my_std::binary_search_tree<T>::level_order(predicate visit) const
{   
    m_level_order_iterative(m_root,visit);
    std::cout << std::endl;
}

template<typename T>
typename my_std::binary_search_tree<T>::value_type my_std::binary_search_tree<T>::get_root_data() const
{
    if(m_root)
    {
        return m_root->m_val;
    }
    throw std::logic_error("BST is empty");
}

template<typename T>
void my_std::binary_search_tree<T>::clear_recursive(Node* node)
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
void my_std::binary_search_tree<T>::clear_iterative(Node* node)
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

        if(temp->m_left)
        {
            q.push(temp->m_left);
        }
        if(temp->m_right)
        {
            q.push(temp->m_right);
        }
        delete temp;
    }
    m_size = 0;
}

template<typename T>
typename my_std::binary_search_tree<T>::Node* my_std::binary_search_tree<T>::m_copy_tree_recursive(Node* node)
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
typename my_std::binary_search_tree<T>::Node* my_std::binary_search_tree<T>::m_min_recursive(Node* node)const
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
typename my_std::binary_search_tree<T>::Node* my_std::binary_search_tree<T>::m_min_iterative(Node* node)const
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
typename my_std::binary_search_tree<T>::Node* my_std::binary_search_tree<T>::m_max_recursive(Node* node)const
{
    if(!node)
    {
        return nullptr;
    }
    else if(node->m_right)
    {
        return m_max_recursive(node->m_right);
    }
    else 
    {
        return node;
    }
}

template <typename T>
typename my_std::binary_search_tree<T>::Node* my_std::binary_search_tree<T>::m_max_iterative(Node* node)const
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
typename my_std::binary_search_tree<T>::size_type my_std::binary_search_tree<T>::m_height_recursive(Node* node) const
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
typename my_std::binary_search_tree<T>::size_type my_std::binary_search_tree<T>::m_height_iterative(Node* node) const
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
typename my_std::binary_search_tree<T>::Node* my_std::binary_search_tree<T>::m_insert_recursive(Node* node, value_type val)
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
    return node;
}

template <typename T>
typename my_std::binary_search_tree<T>::Node* my_std::binary_search_tree<T>::m_insert_iterative(Node* node, value_type val)
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
    return node;
}

template <typename T>
typename my_std::binary_search_tree<T>::Node* my_std::binary_search_tree<T>::m_remove_recursive(Node* node, value_type val)
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
            return node;
        }
        else if(!node->m_right)
        {   
            Node* del = node;
            node = node->m_left;
            --m_size;
            return node;
        }
        else
        {
            Node* successor = m_min_recursive(node->m_right);
            node->m_val = successor->m_val;
            node->m_right = m_remove_recursive(node->m_right,successor->m_val);
            --m_size;        
        }
    }
    return node;
}


template <typename T>
typename my_std::binary_search_tree<T>::Node* my_std::binary_search_tree<T>::m_remove_iterative(Node* node, value_type val)
{
    Node* parent = nullptr;
    Node* current = node;

    while (current && current->m_val != val)
    {
        parent = current;
        if (val < current->m_val)
        {
            current = current->m_left;
        }
        else
        {
            current = current->m_right;
        }
    }

    if (!current)
    {
        return node;
    }

    if (!current->m_left || !current->m_right)
    {
        Node* newChild = (current->m_left) ? current->m_left : current->m_right;

        if (current == node)
        {
            delete current;
            --m_size;
            return newChild;
        }

        if (current == parent->m_left)
        {
            parent->m_left = newChild;
        }
        else
        {
            parent->m_right = newChild;
        }

        delete current;
    }
    else
    {
        Node* successorParent = current;
        Node* successor = current->m_right;

        while (successor->m_left)
        {
            successorParent = successor;
            successor = successor->m_left;
        }

        current->m_val = successor->m_val;

        if (successorParent->m_left == successor)
        {
            successorParent->m_left = successor->m_right;
        }
        else
        {
            successorParent->m_right = successor->m_right;
        }
        delete successor;
    }
    --m_size;
    return node;
}

template <typename T>
void my_std::binary_search_tree<T>::m_inorder_recursive(Node* node, predicate visit) const
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
void my_std::binary_search_tree<T>::m_inorder_iterative(Node* node, predicate visit) const
{   
    if(!node)
    {
        return;
    }
    std::stack<Node*> st;
    Node* temp = node;
    while(temp || !st.empty())
    {
        while(temp)
        {
            st.push(temp);
            temp = temp->m_left;
        }
        temp = st.top();
        visit(temp->m_val);
        st.pop();
        temp = temp->m_right;
    }
}


template <typename T>
void my_std::binary_search_tree<T>::m_preorder_recursive(Node* node, predicate visit) const
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
void my_std::binary_search_tree<T>::m_preorder_iterative(Node* node, predicate visit) const
{   
    if(!node)
    {
        return;
    }
    std::stack<Node*> st;
    Node* temp = node;
    while(temp || !st.empty())
    {
        while(temp)
        {
            visit(temp->m_val);
            st.push(temp);
            temp = temp->m_left;
        }
        temp = st.top();
        st.pop();
        temp = temp->m_right;
    }
}

template <typename T>
void my_std::binary_search_tree<T>::m_postorder_recursive(Node* node, predicate visit) const
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
void my_std::binary_search_tree<T>::m_postorder_iterative(Node* node, predicate visit) const
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
void my_std::binary_search_tree<T>::m_level_order_iterative(Node* node, predicate visit) const
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
typename my_std::binary_search_tree<T>::Node* my_std::binary_search_tree<T>::m_get_Entry_recursive(Node* node, value_type val) const
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
typename my_std::binary_search_tree<T>::Node* my_std::binary_search_tree<T>::m_get_Entry_iterative(Node* node, value_type val) const
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


