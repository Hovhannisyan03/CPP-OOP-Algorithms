#ifndef AVL_H
#define AVL_H

#include <initializer_list>
#include <iostream>
#include <stack>
#include <queue>

template <typename T>
void print(T& val)
{
    std::cout << val << " ";
}

namespace my_std
{
    template <typename T>
    class AVL
    {   
        public:
            using value_type = T;
            using size_type = size_t;
            using reference = value_type &;
            using const_reference = const value_type &;
            using predicate = void(*)(T&);
        private:
            struct Node
            {
                value_type m_val;
                Node* m_left;
                Node* m_right;
                Node();
                Node(value_type val);
            };
       
        public:
            AVL();
            AVL(const_reference val);
            AVL(const AVL& rhv);
            AVL(AVL&& rhv) noexcept;
            AVL(std::initializer_list<value_type> init);
            ~AVL();
        public:
            AVL& operator=(const AVL& rhv);
            AVL& operator=(AVL&& rhv)noexcept;
            AVL& operator=(std::initializer_list<value_type> init);

        public:
            const Node* get_min() const;
            const Node* get_max() const;
            size_type get_height() const;
            void insert(value_type val);
            void remove(value_type val);
            void inorder(predicate visit = print, bool iterative = false) const;
            void preorder(predicate visit = print, bool iterative = false) const;
            void postorder(predicate visit = print, bool iterative = false) const;
            size_type get_number_of_nodes() const;
            value_type get_root_data() const;
            Node* get_Entry(value_type val) const;
            bool contains(value_type val) const;
            void level_order(predicate visit = print, bool recursive = false) const;
            Node* get_successor(Node* node) const;
            Node* get_predecessor(Node* node) const;
        private:
            Node* m_root;
            size_type m_size;

            Node* leftRotate(Node* node);
            Node* rightRotate(Node* node);
            
            int m_balance_factor(Node* node);

            void clear_recursive(Node* node);
            void clear_iterative(Node* node);

            Node* m_copy_tree_recursive(Node* node);

            Node* m_min_recursive(Node* node) const;
            Node* m_max_recursive(Node* node) const;
            Node* m_min_iterative(Node* node) const;
            Node* m_max_iterative(Node* node) const;

            size_type m_height_recursive(Node* node) const;
            size_type m_height_iterative(Node* node) const;

            Node* m_insert_recursive(Node* node, value_type val);
            Node* m_insert_iterative(Node* node, value_type val);

            Node* m_remove_recursive(Node* node, value_type val); 

            void m_inorder_recursive(Node* node, predicate visit) const;
            void m_inorder_iterative(Node* node, predicate visit) const;

            void m_preorder_recursive(Node* node, predicate visit) const;
            void m_preorder_iterative(Node* node, predicate visit) const;
            
            void m_postorder_recursive(Node* node, predicate visit) const;    
            void m_postorder_iterative(Node* node, predicate visit) const;

            void m_level_order_iterative(Node* node, predicate visit) const;
            void m_level_order_recursive(std::queue<Node*>& q, predicate visit) const;

            Node* m_get_Entry_recursive(Node* node, value_type val) const;
            Node* m_get_Entry_iterative(Node* node, value_type val) const;  
   };
}

#include "AVL.hpp"
#endif