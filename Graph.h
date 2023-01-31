#pragma once
using namespace std;
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include "edge.h"
#include "vertex.h"

template <class T>
class Graph
{
protected:
    vector<Vertex<T>> vertices;

public:
    Graph(); //#1 A graph can be empty with no vertex or edge
    Graph(const Graph<T>& g);
    ~Graph();

    size_t addVertex(T data); //#3 A graph can be added in vertices and edges

    size_t getVertexCount() const;

    vector<int> getAllVertexIds() const;

    const Vertex<T>& getVertex(size_t id) const;

    const vector<Vertex<T>>& getVertices() const;

    virtual void print(ostream& out) const = 0;

    friend ostream& operator<<(ostream& out, const Graph& g)   //operator overloading
    {
        g.print(out);
        return out;
    }

    pair<size_t, size_t> addEdgeWithVertex(T start_data, T end_data, int weight = 0);

    void BFS(size_t start_id) const;

    void DFS() const;

    void DFS(size_t vertex_id, vector<bool>& visited) const;

    bool findVertex(T data) const; //#8 A graph can be queried if a value is contained by any of its vertex.

    bool findEdge(size_t start_id, size_t end_id); //#7 A graph can be queried by given an edge, if this edge exists in the graph.

    void listAllPaths() const; //#5 A graph can be displayed by listing all the possible paths, each linking vertices.

    void listAllPaths(size_t vertex_id, vector<bool>& visited, string path) const;

    void pathFrom(size_t start_id) const; //#6 A graph can be queried by given a starting vertex, listing the path this vertex leads

    void pathFrom(size_t start_id, vector<bool>& visited, string path) const;
    virtual void addEdge(size_t start_id, size_t end_id, int weight = 0) = 0;
};