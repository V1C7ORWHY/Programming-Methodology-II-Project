#include "Vertex.h"

template <class T>
Vertex<T>::Vertex()
{
}

template <class T>
Vertex<T>::Vertex(const Vertex<T>& v)
{
    id = v.id;
    data = v.data;
    edges = v.edges;
}

template <class T>
Vertex<T>::Vertex(size_t _id, T _data)
{
    id = _id;
    data = _data;
}

template <class T>
Vertex<T>::~Vertex()
{
}

template <class T>
void Vertex<T>::addEdge(size_t end_id, int weight)
{
    Edge e(end_id, weight);
    edges.push_back(e);
}

template <class T>
void Vertex<T>::removeEdge(size_t end_id)
{
    for (size_t i = 0; i < edges.size(); i++)
    {
        if (edges[i].dest_id == end_id)
        {
            edges.erase(edges.begin() + i);
            break;
        }
    }
}

template <class T>
const T& Vertex<T>::getData() const
{
    return data;
}

template <class T>
const vector<Edge>& Vertex<T>::getEdges() const
{
    return edges;
}

template <class T>
size_t Vertex<T>::getId() const
{
    return id;
}