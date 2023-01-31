#include <iostream>
#include <string>
#include "vertex.cpp"
#include "edge.h"
#include "graph.h"
#include "graph.cpp"
#include "DirectedGraph.h"
#include "DirectedGraph.cpp"
#include "UndirectedGraph.h"
#include "UndirectedGraph.cpp"
using namespace std;

int main(int argc, char** argv)
{
    Graph<string>* g = nullptr;
    g = new DirectedGraph<string>();
    
    auto id_ab = g->addEdgeWithVertex("A", "B");
    auto id_cg = g->addEdgeWithVertex("C", "G");
    auto id_ef = g->addEdgeWithVertex("E", "F");
    size_t id_d = g->addVertex("D");

    g->addEdge(id_ab.first, id_ef.first);   // A -> E
    g->addEdge(id_ab.first, id_cg.first);   // A -> C
    g->addEdge(id_ab.second, id_d);         // B -> D
    g->addEdge(id_ab.second, id_ef.second); // B -> F

    cout << *g << endl;

    cout << "BFS start from " << g->getVertex(id_ab.first).getData() << ": " << endl;
    g->BFS(id_ab.first);
    cout << endl
        << endl;

    cout << "DFS start: " << endl;
    g->DFS();
    cout << endl;

    cout << "Print path from A:" << endl;
    g->pathFrom(id_ab.first);
    cout << endl;

    cout << "List all paths: " << endl;
    g->listAllPaths();
    cout << endl;

    cout << endl;
    if (g->findVertex("B"))
    {
        cout << "B is in the graph" << endl;
    }
    else
    {
        cout << "B is not in the graph" << endl;
    }

    cout << endl;
    if (g->findVertex("H"))
    {
        cout << "H is in the graph" << endl;
    }
    else
    {
        cout << "H is not in the graph" << endl;
    }

    cout << endl;
    if (g->findEdge(id_ab.first, id_ef.second))
    {
        cout << "Edge " << g->getVertex(id_ab.first).getData() << "->" << g->getVertex(id_ef.second).getData() << " exists" << endl;
    }
    else
    {
        cout << "Edge " << g->getVertex(id_ab.first).getData() << "->" << g->getVertex(id_ef.second).getData() << " does not exist" << endl;
    }

    cout << "==========================================================" << endl;

    delete g;
    g = new UndirectedGraph<string>();

    id_ab = g->addEdgeWithVertex("A", "B");
    id_cg = g->addEdgeWithVertex("C", "G");
    id_ef = g->addEdgeWithVertex("E", "F");
    id_d = g->addVertex("D");

    g->addEdge(id_ab.first, id_ef.first);   // A -> E
    g->addEdge(id_ab.first, id_cg.first);   // A -> C
    g->addEdge(id_ab.second, id_d);         // B -> D
    g->addEdge(id_ab.second, id_ef.second); // B -> F

    cout << *g << endl;

    cout << "BFS start from " << g->getVertex(id_ab.first).getData() << ": " << endl;
    g->BFS(id_ab.first);
    cout << endl
        << endl;

    cout << "DFS start: " << endl;
    g->DFS();
    cout << endl;

    cout << "Print path from A:" << endl;
    g->pathFrom(id_ab.first);
    cout << endl;

    cout << "List all paths: " << endl;
    g->listAllPaths();

    cout << endl;
    if (g->findVertex("B"))
    {
        cout << "B is in the graph" << endl;
    }
    else
    {
        cout << "B is not in the graph" << endl;
    }

    cout << endl;
    if (g->findVertex("H"))
    {
        cout << "H is in the graph" << endl;
    }
    else
    {
        cout << "H is not in the graph" << endl;
    }

    cout << endl;
    if (g->findEdge(id_ab.first, id_ef.second))
    {
        cout << "Edge " << g->getVertex(id_ab.first).getData() << "->" << g->getVertex(id_ef.second).getData() << " exists" << endl;
    }
    else
    {
        cout << "Edge " << g->getVertex(id_ab.first).getData() << "->" << g->getVertex(id_ef.second).getData() << " does not exist" << endl;
    }

    delete g;

    return 0;
}