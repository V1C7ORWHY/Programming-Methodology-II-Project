#pragma once

#include <iostream>

class Edge
{
private:
    size_t dest_id;
    int weight;

public:
    Edge(size_t _end_id, int _weight);
    Edge(const Edge& e);
    ~Edge();

    size_t getDestId() const;

    int getWeight() const;
};