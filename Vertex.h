#pragma once
using namespace std;
#include "edge.h"
#include <vector>

template <class T> //template
class Vertex
{
private:
    T data;   //#4. A vertex of a graph can contain values, -in theory, the value can be of any type
    size_t id;               // id of the vertex
    std::vector<Edge> edges; // list of edges
public:
    Vertex();
    Vertex(const Vertex<T>& v);
    Vertex(size_t _id, T _data);
    ~Vertex();
    //#9

    void addEdge(size_t end_id, int weight); //#3 A graph can be added in vertices and edges
    void removeEdge(size_t end_id);

    const T& getData() const;

    const vector<Edge>& getEdges() const;

    size_t getId() const;
};