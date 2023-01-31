#pragma once
#include "graph.h"

template <class T>
class UndirectedGraph : public Graph<T> //#2 A graph can be either a directed graph or an undirected graph
{
public:
    UndirectedGraph();
    UndirectedGraph(const UndirectedGraph<T>& g);
    ~UndirectedGraph();

    void print(ostream& out) const;

    void addEdge(size_t start_id, size_t end_id, int weight = 0);
};