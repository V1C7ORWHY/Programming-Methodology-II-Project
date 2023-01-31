#include "Edge.h"


Edge::Edge(size_t _end_id, int _weight)
{
    dest_id = _end_id;
    weight = _weight;
}

Edge::Edge(const Edge& e)
{
    dest_id = e.dest_id;
    weight = e.weight;
}

Edge::~Edge()
{
}

size_t Edge::getDestId() const
{
    return dest_id;
}

int Edge::getWeight() const
{
    return weight;
}