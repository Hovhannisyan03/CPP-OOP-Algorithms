#include "graph.h"

namespace my_graph
{
    template <typename T>
    Graph<T>::Graph(size_type size) : m_adjacency_matrix(size,std::vector<bool>(size,0)) {}

    template<typename T>
    void Graph<T>::add_edge(value_type u, value_type v)
    {
        if(u < m_adjacency_matrix.size() && v < m_adjacency_matrix.size())
        {
            m_adjacency_matrix[u][v] = true;
            m_adjacency_matrix[v][u] = true; // comment this line for a directed graph
        }
        else
        {
            throw std::out_of_range("Out of range");
        }
    }

    template <typename T>
    void Graph<T>::add_vertex()
    {   
        size_type new_size = m_adjacency_matrix.size() + 1;
        m_adjacency_matrix.resize(new_size);
        for(size_type i = 0; i < new_size; ++i)
        {
            m_adjacency_matrix[i].resize(new_size);
        }
    }

    template <typename T>
    void Graph<T>::print() const
    {
        for(size_type i = 0; i < m_adjacency_matrix.size(); ++i)
        {   
            std::cout << i << ": ";
            for(size_type j = 0; j < m_adjacency_matrix.size(); ++j)
            {   
                if(m_adjacency_matrix[i][j])
                {
                    std::cout << j << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    template <typename T>
    void Graph<T>::DFS_I() const
    {
        std::vector<bool> visited(m_adjacency_matrix.size(),false);
        for(size_type i = 0; i < m_adjacency_matrix.size(); ++i)
        {
            if(!visited[i])
            {
                m_DFS_Iter_helper(i,visited);
            }
        }
        std::cout << std::endl;
    }

    template <typename T>
    void Graph<T>::m_DFS_Iter_helper(value_type v, std::vector<bool>& visited) const
    {
        std::stack<value_type> s;
        s.push(v);
        visited[v] = true;

        while(!s.empty()) 
        {
            value_type u = s.top();
            std::cout << u << " ";
            s.pop();

            for(size_type i = 0; i < m_adjacency_matrix.size(); ++i) 
            {
                if(m_adjacency_matrix[u][i] && !visited[i]) 
                {
                    s.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    template <typename T>
    void Graph<T>::DFS_R() const
    {
        std::vector<bool> visited(m_adjacency_matrix.size(), false);

        for(size_type i = 0; i < m_adjacency_matrix.size(); ++i)
        {
            if(!visited[i])
            {
                m_DFS_Rec_helper(i,visited);
            }
        }
        std::cout << std::endl;
    }

    template <typename T>
    void Graph<T>::m_DFS_Rec_helper(value_type v, std::vector<bool>& visited) const
    {
        visited[v] = true;
        std::cout << v << " ";

        for(size_type i = 0; i < m_adjacency_matrix.size(); ++i)
        {
            if(m_adjacency_matrix[v][i] == true && !visited[i])
            {
                m_DFS_Rec_helper(i,visited);
            }
        }
    }
    
    template<typename T>
    void Graph<T>::BFS() const 
    {
        std::vector<bool> visited(m_adjacency_matrix.size(), false);
        std::queue<int> q;
        
        for(int i = 0; i < m_adjacency_matrix.size(); ++i) 
        {
            if(!visited[i]) 
            {
                visited[i] = true;
                q.push(i);

                while(!q.empty()) 
                {
                    int v = q.front();
                    q.pop();
                    std::cout << v << " ";

                    for (int j = 0; j < m_adjacency_matrix.size(); ++j) 
                    {
                        if (m_adjacency_matrix[v][j] == 1 && !visited[j]) 
                        {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        std::cout << std::endl;
    }


    template <typename T>
    typename Graph<T>::size_type Graph<T>::getCountNthLevel(value_type v, value_type level) const
    {
        std::vector<bool> visited(m_adjacency_matrix.size(), false);
        std::queue<value_type> q;
        q.push(v);
        visited[v] = true;

        size_type currentLevel = 0;
        size_type countAtLevel = 0;

        while (!q.empty()) 
        {
            size_type levelSize = q.size(); 
            if (currentLevel == level) 
            {
                return levelSize;
            }

            for (size_type i = 0; i < levelSize; ++i) 
            {
                value_type u = q.front();
                q.pop();

                for (size_type j = 0; j < m_adjacency_matrix.size(); ++j) 
                {
                    if (m_adjacency_matrix[u][j] && !visited[j]) 
                    {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }

            ++currentLevel;
        }

        return 0;
    }

    //Uncomment for directed graph
    // template <typename T>
    // void Graph<T>::transpose() 
    // {
    //     std::vector<std::vector<bool>> new_graph(m_adjacency_matrix.size(),std::vector<bool>(m_adjacency_matrix.size(),false));

    //     for(size_type i = 0; i < m_adjacency_matrix.size(); ++i)
    //     {
    //         for(size_type j = 0; j < m_adjacency_matrix.size(); ++j)
    //         {
    //             if(m_adjacency_matrix[i][j])
    //             {
    //                 new_graph[j][i] = true;
    //             }
    //         }
    //     }

    //     m_adjacency_matrix = new_graph;
    // }

}