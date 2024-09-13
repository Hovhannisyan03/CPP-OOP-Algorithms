#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stack>
#include <iostream>
#include <queue>

namespace my_graph
{
    template <typename T>
    class Graph
    {
        public:
            using value_type = T;
            using size_type = size_t;
            Graph(size_type size);
            void add_edge(value_type u, value_type v);
            void add_vertex();
            void print() const;
            void DFS_R() const;
            void DFS_I() const;
            void BFS_R() const;
            void BFS_I() const;
            size_type getCountNthLevel(value_type v, size_type level) const;
            size_type getCountNthLevelWithDFS(value_type v, size_type level) const;
            // void transpose();//Uncomment for undirected graph
            
            std::vector<value_type> get_shortest_path(value_type u, value_type v) const;
            std::vector<std::vector<value_type>> get_all_possible_paths(value_type u, value_type v) const;

            bool is_Cycle() const;

        private:
            std::vector<std::vector<value_type>> m_adjacency_list;
            void m_DFS_Rec_helper(value_type v, std::vector<bool>& visited) const;
            void m_DFS_Iter_helper(value_type v, std::vector<bool>& visited) const;

            void m_BFS_Rec_helper(std::queue<value_type> q, std::vector<bool>& visited) const;
            void m_BFS_Iter_helper(value_type v, std::vector<bool>& visited) const;

            void m_getCountNthLevelWithDFS_helper(value_type v, size_type current_level, size_type level, size_type& count, std::vector<bool>& visited) const;

            std::vector<value_type> m_get_shortest_path_helper(std::vector<value_type>& parent, value_type v) const;
            void m_get_all_possible_paths_helper(value_type u, value_type v, std::vector<value_type>& path, std::vector<std::vector<value_type> >& all_paths, std::vector<bool>& visited) const;
            bool m_is_Cycle_DFS(value_type u, std::vector<bool>& visited, value_type parent) const;
    
    };
}
#include "graph.hpp"
#endif
