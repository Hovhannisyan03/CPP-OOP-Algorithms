#ifndef BST_H
#define BST_H

#include <initializer_list>
#include <iostream>
#include <stack>
#include <queue>
namespace my_std
{
    template <typename T>
    class binary_search_tree
    {   
        public:
            using value_type = T;
            using size_type = size_t;

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
            binary_search_tree();
            binary_search_tree(const binary_search_tree& rhv);
            binary_search_tree(binary_search_tree&& rhv) noexcept;
            binary_search_tree(std::initializer_list<value_type> init);
            ~binary_search_tree();
        public:
            binary_search_tree& operator=(const binary_search_tree& rhv);
            binary_search_tree& operator=(binary_search_tree&& rhv)noexcept;
            binary_search_tree& operator=(std::initializer_list<value_type> init);

        public:
            const Node* get_min() const;
            const Node* get_max() const;
            size_type get_height() const;
            void insert(value_type val);
            void remove(value_type val);
            void inorder(bool recursive = true) const;
            void preorder(bool recursive = true) const;
            void postorder(bool recursive = true) const;
            size_type get_number_of_nodes() const;
            value_type get_root_data() const;
            value_type get_Entry(value_type val) const;
            bool contains(value_type val) const;

        private:
            Node* m_root;
            size_type m_size;
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
            Node* m_remove_iterative(Node* node, value_type val); 

            void m_inorder_recursive(Node* node) const;
            void m_inorder_iterative(Node* node) const;

            void m_preorder_recursive(Node* node) const;
            void m_preorder_iterative(Node* node) const;
            
            void m_postorder_recursive(Node* node) const;    
            void m_postorder_iterative(Node* node) const;

            void m_level_order_iterative(Node* node) const;

            Node* m_get_Entry_recursive(Node* node, value_type val) const;
            Node* m_get_Entry_iterative(Node* node, value_type val) const;  
    };
}

#include "BST.hpp"
#endif
