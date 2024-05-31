#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>

class Graph
{
public:
    Graph(size_t count);
    void addVertex();
    void deleteVertex(size_t vertex);
    void addEdge(size_t v1, size_t v2);
    void deleteEdge(size_t v1, size_t v2);
    void displayGraph();
    size_t countOfEdge();
    size_t countOfVertex();
    bool checkEdge(size_t v1, size_t v2);
private:
    void reserve();
    bool **m_graph;
    size_t m_V;
    size_t m_E;
};

#endif