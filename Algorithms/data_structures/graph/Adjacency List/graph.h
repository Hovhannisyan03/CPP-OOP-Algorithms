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
            value_type getCountNthLevel(value_type v, value_type level) const;
            value_type getCountNthLevelWithDFS(value_type v, value_type level) const;
            // void transpose();//Uncomment for undirected graph
            
            // std::vector<value_type> get_shortest_path(value_type u, value_type v);
            // std::vector<std::vector<value_type>> get_all_possible_paths(value_type src, value_type dest) const;

        private:
            std::vector<std::vector<value_type>> m_adjacency_list;
            void m_DFS_Rec_helper(value_type v, std::vector<bool>& visited) const;
            void m_DFS_Iter_helper(value_type v, std::vector<bool>& visited) const;

            void m_BFS_Rec_helper(std::queue<value_type> q, std::vector<bool>& visited) const;
            void m_BFS_Iter_helper(value_type v, std::vector<bool>& visited) const;

            void m_getCountNthLevelWithDFS_helper(value_type v, value_type currLevel, value_type level, value_type& count, std::vector<bool>& visited) const;
            // void dfsAllPaths(value_type src, value_type dest, std::vector<value_type>& tmp, std::vector<std::vector<value_type> >& res, std::vector<bool>& visit) const;
    };
}
#include "graph.hpp"
#endif