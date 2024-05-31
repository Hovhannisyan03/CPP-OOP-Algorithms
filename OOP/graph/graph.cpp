#include "graph.h"

Graph::Graph(size_t count) : m_V{count}, m_graph{nullptr}, m_E{0}
{
    reserve();
}

void Graph::addVertex()
{
    ++m_V;
    reserve();
}

void Graph::deleteVertex(size_t vertex)
{
    if(vertex >= 0 && vertex < m_V)
    {
        for(size_t i = 0; i < m_V; ++i)
        {
            m_graph[i][vertex] = 0;
            m_graph[vertex][i] = 0;
        }
    }
    else
    {
        throw std::out_of_range("Out of Range");
    }

} 

void Graph::addEdge(size_t v1, size_t v2)
{
    if(v1 >= 0 && v1 < m_V && v2 >= 0 && v2 < m_V)
    {
        if(m_graph[v1][v2])
        {
            std::cout << "such edge exists" << std::endl;
            return;
        }
        m_graph[v1][v2] = 1;
        m_graph[v2][v1] = 1;
        ++m_E;
    }
    else
    {
        throw std::out_of_range("Out of Range");
    }
}

void Graph::deleteEdge(size_t v1, size_t v2)
{
    if(v1 >= 0 && v1 < m_V && v2 >= 0 && v2 < m_V)
    {
        if(!m_graph[v1][v2])
        {
            std::cout << "no such edge exists" << std::endl;
            return;
        }
        m_graph[v1][v2] = 0;
        m_graph[v2][v1] = 0;
        --m_E;
    } 
    else
    {
        throw std::out_of_range("Out of Range");
    }
}

void Graph::reserve()
{
    bool **newV = new bool*[m_V]{0};
    for(size_t i = 0; i < m_V; ++i)
    {
        newV[i] = new bool[m_V]{0};
    }

    if(!m_graph)
    {
        m_graph = newV;
        newV = nullptr;
        return;
    }
    
    for(size_t i = 0; i < m_V - 1; ++i)
    {
        for (size_t j = 0; j < m_V - 1; ++j)
        {
            newV[i][j] = m_graph[i][j];
        }
    }

    bool **tmp = m_graph;
    m_graph = newV;
    
    for(size_t i = 0; i < m_V - 1; ++i)
    {
        delete tmp[i];
    }
    delete tmp;
    tmp = nullptr;
}

void Graph::displayGraph()
{
    for(size_t i = 0; i < m_V; ++i)
    {
        std::cout << i << "-> ";
        for(size_t j = 0; j < m_V; ++j)
        {
            if(m_graph[i][j])
            {
                std::cout << j << ", ";
            }
        }
        std::cout << std::endl;
    }
}

size_t Graph::countOfEdge()
{
    return m_E;
}

size_t Graph::countOfVertex()
{
    return m_V;
}

bool Graph::checkEdge(size_t v1, size_t v2)
{
    if(v1 >= 0 && v1 < m_V && v2 >= 0 && v2 < m_V)
    {
        return m_graph[v1][v2];
    }
    throw std::out_of_range("Out of range");
}


