#include "DirectedGraph.h"

template <class T>
DirectedGraph<T>::DirectedGraph(){
    Graph<T>();
}

template <class T>
DirectedGraph<T>::DirectedGraph(const DirectedGraph<T>& g){
    Graph<T>(g);
}

template <class T>
DirectedGraph<T>::~DirectedGraph() {}

template <class T>
void DirectedGraph<T>::print(ostream& out) const
{
    out << "DirectedGraph: " << endl;
    for (const auto v : this->vertices)
    {
        out << v.getData() << " ";
    }
    out << endl;

    out << "Edges: " << endl;
    for (size_t i = 0; i < this->vertices.size(); i++)
    {
        out << "[" << this->vertices[i].getData() << ": ";
        for (const auto e : this->vertices[i].getEdges())
        {
            out << " " << this->vertices[e.getDestId()].getData();
        }
        out << " ] ";
    }
    out << endl;
}

// this function adds an edge from start_id to end_id
template <class T>
void DirectedGraph<T>::addEdge(size_t start_id, size_t end_id, int weight)
{
    // check if start_id and end_id are valid
    if (start_id < 0 || start_id >= this->getVertexCount() || end_id < 0 || end_id >= this->getVertexCount())
    {
        cerr << "Invalid vertex id" << endl;
        return;
    }
    this->vertices[start_id].addEdge(end_id, weight);
}