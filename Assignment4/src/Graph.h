#pragma once
#ifndef SRC_GRAPH_H
#define SRC_GRAPH_H

#include <vector>
#include <set>
#include <map>
#include "Point3D.h"

class Graph
{
public:
    bool loadCityInformation(const char* filename);
    void Generate();
    void Print();
    void showConnectivity(int a);

private:
    std::vector<Point3D> cityCoordinates;
    std::vector<int> cityIndices;
    std::map<int, std::set<int>> Connectivity;
};

#endif