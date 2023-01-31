#include "Graph.h"

template <class T>
Graph<T>::Graph() {
    cout << "This graph is empty." << endl;
}

template <class T>
Graph<T>::Graph(const Graph<T>& g) {
    vertices = g.vertices;
}

template <class T>
Graph<T>::~Graph() {}

template <class T>
size_t Graph<T>::addVertex(T data)
{
    size_t id = getVertexCount();
    vertices.push_back(Vertex<T>(id, data));
    return id;
}

template <class T>
size_t Graph<T>::getVertexCount() const { 
    return vertices.size(); 
}

template <class T>
vector<int> Graph<T>::getAllVertexIds() const
{
    vector<int> ids;
    for (size_t i = 0; i < vertices.size(); i++)
    {
        ids.push_back(vertices[i].getId());
    }
    return ids;
}

template <class T>
const Vertex<T>& Graph<T>::getVertex(size_t id) const { return vertices[id]; }

template <class T>
const vector<Vertex<T>>& Graph<T>::getVertices() const { return vertices; }

template <class T>
pair<size_t, size_t> Graph<T>::addEdgeWithVertex(T start_data, T end_data, int weight)
{
    size_t start_id = addVertex(start_data);
    size_t end_id = addVertex(end_data);
    addEdge(start_id, end_id, weight);
    return make_pair(start_id, end_id);
}

template <class T>
void Graph<T>::BFS(size_t start_id) const
{
    vector<bool> visited(vertices.size(), false);
    queue<size_t> q;
    visited[start_id] = true;
    q.push(start_id);

    while (!q.empty())
    {
        start_id = q.front();
        cout << vertices[start_id].getData() << " ";
        q.pop();
        for (auto e : vertices[start_id].getEdges())
        {
            size_t neighbor_id = e.getDestId();
            if (!visited[neighbor_id])
            {
                visited[neighbor_id] = true;
                q.push(neighbor_id);
            }
        }
    }
}

template <class T>
void Graph<T>::DFS() const
{
    vector<bool> visited(getVertexCount(), false);

    for (size_t i = 0; i < getVertexCount(); i++)
    {
        if (!visited[i])
        {
            DFS(i, visited);
        }
    }
    return;
}

template <class T>
void Graph<T>::DFS(size_t vertex_id, vector<bool>& visited) const
{
    stack<size_t> s;
    s.push(vertex_id);

    while (!s.empty())
    {
        vertex_id = s.top();
        s.pop();
        if (!visited[vertex_id])
        {
            visited[vertex_id] = true;
            cout << vertices[vertex_id].getData() << " ";
        }

        for (auto e : vertices[vertex_id].getEdges())
        {
            size_t neighbor_id = e.getDestId();
            if (!visited[neighbor_id])
            {
                s.push(neighbor_id);
            }
        }
    }
}

template <class T>
bool Graph<T>::findVertex(T data) const 
{                                       
    for (const auto v : vertices)
    {
        if (v.getData() == data)
        {
            return true;
        }
    }
    return false; 
}

template <class T>
bool Graph<T>::findEdge(size_t start_id, size_t end_id) 
{
    if (start_id < 0 || start_id >= this->getVertexCount() || end_id < 0 || end_id >= this->getVertexCount())
    {
        cerr << "Invalid vertex id" << endl;
        return false;
    }
    for (const auto e : this->vertices[start_id].getEdges())
    {
        if (e.getDestId() == end_id)
        {
            return true;
        }
    }
    return false;
}

template <class T>
void Graph<T>::listAllPaths() const 
{
    vector<bool> visited(getVertexCount(), false);
    for (size_t i = 0; i < getVertexCount(); i++)
    {
        if (!visited[i])
        {
            listAllPaths(i, visited, "");
        }
    }
}

template <class T>
void Graph<T>::listAllPaths(size_t vertex_id, vector<bool>& visited, string path) const
{
    visited[vertex_id] = true;
    path += vertices[vertex_id].getData();
    if (path.size() > 1)
    {
        cout << path << endl;
    }

    for (auto e : vertices[vertex_id].getEdges())
    {
        size_t neighbor_id = e.getDestId();
        if (!visited[neighbor_id])
        {
            listAllPaths(neighbor_id, visited, path + "->");
        }
    }
    visited[vertex_id] = false;
}

template <class T>
void Graph<T>::pathFrom(size_t start_id) const 
{
    vector<bool> visited(getVertexCount(), false);
    pathFrom(start_id, visited, "");
}

template <class T>
void Graph<T>::pathFrom(size_t start_id, vector<bool>& visited, string path) const
{
    visited[start_id] = true;
    path += vertices[start_id].getData();
    if (path.size() > 1)
    {
        cout << path << endl;
    }

    for (auto e : vertices[start_id].getEdges())
    {
        size_t neighbor_id = e.getDestId();
        if (!visited[neighbor_id])
        {
            pathFrom(neighbor_id, visited, path + "->");
        }
    }
    visited[start_id] = false;
}