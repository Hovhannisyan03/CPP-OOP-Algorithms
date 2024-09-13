#include "graph.h"

namespace my_graph
{
    template <typename T>
    Graph<T>::Graph(size_type size) : m_adjacency_list(size){}

    template <typename T>
    void Graph<T>::add_edge(value_type u, value_type v)
    {
        if(u < m_adjacency_list.size() && v < m_adjacency_list.size())
        {
            m_adjacency_list[u].push_back(v);
            m_adjacency_list[v].push_back(u);// comment this line for a directed graph
        }
        else
        {
            throw std::out_of_range("Out of range");
        }
    }

    template <typename T>
    void Graph<T>::add_vertex() 
    {
        m_adjacency_list.emplace_back();
    }

    template <typename T>
    void Graph<T>::DFS_R() const
    {
        std::vector<bool> visited(m_adjacency_list.size(),false);
        for(size_type i = 0; i < m_adjacency_list.size(); ++i)
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
        for(const auto& elem : m_adjacency_list[v])
        {
            if(!visited[elem])
            {
                m_DFS_Rec_helper(elem,visited);
            }
        }
    }

    template <typename T>
    void Graph<T>::DFS_I() const
    {
        std::vector<bool> visited(m_adjacency_list.size(),false);
        for(size_type i = 0; i < m_adjacency_list.size(); ++i)
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

            for(const auto& elem : m_adjacency_list[u]) 
            {
                if(!visited[elem]) 
                {
                    s.push(elem);
                    visited[elem] = true;
                }
            }
        }
    }

   
    template <typename T>
    void Graph<T>::BFS_I() const
    {
        std::vector<bool> visited(m_adjacency_list.size(), false);
        for(size_type i = 0; i < m_adjacency_list.size(); ++i) 
        {
            if(!visited[i]) 
            {
                m_BFS_Iter_helper(i, visited);
            }
        }
        std::cout << std::endl;
    }

    template <typename T>
    void Graph<T>::m_BFS_Iter_helper(value_type v, std::vector<bool>& visited) const
    {
        std::queue<value_type> q;
        q.push(v);
        visited[v] = true;

        while (!q.empty()) 
        {
            value_type u = q.front();
            q.pop();
            std::cout << u << " ";

            for (const auto& elem : m_adjacency_list[u]) 
            {
                if (!visited[elem]) 
                {
                    q.push(elem);
                    visited[elem] = true;
                }
            }
        }
    }

    template <typename T>
    void Graph<T>::BFS_R() const
    {
        std::vector<bool> visited(m_adjacency_list.size(), false);
        for (size_type i = 0; i < m_adjacency_list.size(); ++i) 
        {
            if (!visited[i]) 
            {
                std::queue<value_type> q;
                q.push(i);
                visited[i] = true;
                m_BFS_Rec_helper(q, visited);
            }
        }
        std::cout << std::endl;
    }

    template <typename T>
    void Graph<T>::m_BFS_Rec_helper(std::queue<value_type> q, std::vector<bool>& visited) const
    {
        if (q.empty()) 
        {
            return; 
        }

        value_type u = q.front();
        q.pop();
        std::cout << u << " ";

        for(const auto& elem : m_adjacency_list[u]) 
        {
            if(!visited[elem]) 
            {
                q.push(elem);
                visited[elem] = true;
            }
        }

        m_BFS_Rec_helper(q, visited);
    }

    template <typename T>
    void Graph<T>::print() const
    {
        for(size_type i = 0; i < m_adjacency_list.size(); ++i)
        {   
            std::cout << i << ": ";
            for(const auto& elem : m_adjacency_list[i])
            {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }

    template <typename T>
    typename Graph<T>::size_type Graph<T>::getCountNthLevelWithDFS(value_type v, size_type level) const
    {
        if(v >= m_adjacency_list.size())
        {
            throw std::out_of_range("Out of range");
        }

        std::vector<bool> visited(m_adjacency_list.size(), false);
        size_type count = 0;

        m_getCountNthLevelWithDFS_helper(v, 0, level, count, visited);
        return count;
    }

    template <typename T>
    void Graph<T>::m_getCountNthLevelWithDFS_helper(value_type v, size_type current_level, size_type level, size_type& count, std::vector<bool>& visited) const
    {
        visited[v] = true;

        if(current_level == level)
        {
            ++count;
        }
        if(current_level > level)
        {
            return;
        }

        for(const auto& elem : m_adjacency_list[v])
        {
            if(!visited[elem])
            {
                m_getCountNthLevelWithDFS_helper(elem, current_level + 1, level, count, visited);
            }
        }
    }

    template <typename T>
    typename Graph<T>::size_type Graph<T>::getCountNthLevel(value_type v, size_type level) const
    {
        std::vector<bool> visited(m_adjacency_list.size(), false);
        std::queue<value_type> q;
        q.push(v);
        visited[v] = true;
        while(!q.empty()) 
        {
            value_type u = q.front();
            q.pop();
            --level;
            for(const auto& elem : m_adjacency_list[u]) 
            {
                if(!visited[elem]) 
                {
                    q.push(elem);
                    visited[elem] = true;
                }
            }
            if(level == 0)
            {
                break;
            }
        }

        return q.size();
    }   

    template <typename T>
    std::vector<typename Graph<T>::value_type> Graph<T>::get_shortest_path(value_type u, value_type v) const
    {
        std::vector<bool> visited(m_adjacency_list.size(),false);
        std::queue<value_type> q;
        std::vector<value_type> parent(m_adjacency_list.size(), - 1);
        q.push(u);
        visited[u] = true;
        while(!q.empty())
        {
            value_type vertex = q.front();
            q.pop();

            if (vertex == v) 
            {
                break;
            }

            for(const auto& elem : m_adjacency_list[vertex])
            {
                if(!visited[elem])
                {
                    visited[elem] = true;
                    parent[elem] = vertex;
                    q.push(elem);
                }
            }
        }
    
        return m_get_shortest_path_helper(parent,v);
    }

    template <typename T>
    std::vector<std::vector<typename Graph<T>::value_type>> Graph<T>::get_all_possible_paths(value_type u, value_type v) const
    {
        std::vector<bool> visited(m_adjacency_list.size(), false);
        std::vector<value_type> path;
        std::vector<std::vector<value_type>> all_paths;
        
        m_get_all_possible_paths_helper(u, v, path, all_paths, visited);
        return all_paths;

    }

    template <typename T>
    void Graph<T>::m_get_all_possible_paths_helper(value_type u, value_type v, std::vector<value_type>& path, std::vector<std::vector<value_type>>& all_paths, std::vector<bool>& visited) const
    {
        visited[u] = true;
        path.push_back(u);
        if(u == v)
        {
            all_paths.push_back(path);
            path.pop_back();
            visited[u] = false;
            return;
        }
        for(const auto& elem : m_adjacency_list[u])
        {
            if(!visited[elem])
            {
                
                visited[elem] = true;
                m_get_all_possible_paths_helper(elem,v,path,all_paths,visited);
            }
        }
        visited[u] = false;
        path.pop_back();
    }


    template <typename T>
    std::vector<typename Graph<T>::value_type> Graph<T>::m_get_shortest_path_helper(std::vector<value_type>& parent, value_type v) const
    {    
        if(parent[v] == -1)
        {
            return {};
        }
        std::vector<value_type> path;
        while(parent[v] != -1)
        {       
            path.push_back(v);
            v = parent[v];
        }
        path.push_back(v);

        std::reverse(path.begin(), path.end());
        return path;
    }

    //Uncomment for directed graph
    // template <typename T>
    // void Graph<T>::transpose()
    // {
    //     std::vector<std::vector<value_type>> new_graph(m_adjacency_list.size());
    //     for(size_type i = 0; i < m_adjacency_list.size(); ++i)
    //     {
    //         for(const auto& elem : m_adjacency_list[i])
    //         {
    //             new_graph[elem].push_back(i);
    //         }
    //     }
    //     m_adjacency_list = std::move(new_graph);
    // } 

    template <typename T>
    bool Graph<T>::is_Cycle() const
    {
        std::vector<bool> visited(m_adjacency_list.size(),false);

        for (size_t i = 0; i < visited.size(); ++i)
        {
            if (!visited[i]) 
            {
                if (m_is_Cycle_DFS(i, visited, -1)) 
                {
                    return true;
                }
            }
        }
        return false;
    }

    template <typename T>
    bool Graph<T>::m_is_Cycle_DFS(value_type u, std::vector<bool>& visited, value_type parent) const
    {
        visited[u] = true;

        for(const auto& v : m_adjacency_list[u])
        {
            if(!visited[v])
            {
                if(m_is_Cycle_DFS(v,visited,u))
                {
                    return true;
                }
            }
            else if(v != parent)
            {
                return true;
            }
        }
        return false;
    }
}
