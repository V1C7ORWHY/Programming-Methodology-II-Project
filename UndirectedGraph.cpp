#include "UndirectedGraph.h"

template <class T>
UndirectedGraph<T>::UndirectedGraph(){
    Graph<T>();
}

template <class T>
UndirectedGraph<T>::UndirectedGraph(const UndirectedGraph<T>& g){
    Graph<T>(g);
}

template <class T>
UndirectedGraph<T>::~UndirectedGraph() {}

template <class T>
void UndirectedGraph<T>::print(ostream& out) const
{
    out << "UndirectedGraph: " << endl;
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

template <class T>
void UndirectedGraph<T>::addEdge(size_t start_id, size_t end_id, int weight)
{
    if (start_id < 0 || start_id >= this->getVertexCount() || end_id < 0 || end_id >= this->getVertexCount())
    {
        cerr << "Invalid vertex id" << endl;
        return;
    }
    this->vertices[start_id].addEdge(end_id, weight);
    this->vertices[end_id].addEdge(start_id, weight);
}