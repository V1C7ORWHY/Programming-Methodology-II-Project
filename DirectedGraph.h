#pragma once
#include "graph.h"

template <class T>
class DirectedGraph : public Graph<T> //#2 A graph can be either a directed graph or an undirected graph
{ //inheritance
public:
    DirectedGraph();
    DirectedGraph(const DirectedGraph<T>& g);
    ~DirectedGraph();

    void print(ostream& out) const;

    // this function adds an edge from start_id to end_id
    void addEdge(size_t start_id, size_t end_id, int weight = 0);
};