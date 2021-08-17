#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <iostream>
#include <vector>

using namespace std;

class knapsack {
    double cap;
    vector<size_t> items;
    
    public:

    knapsack(double cap_in, vector<size_t> items_in) : cap(cap_in), items(items_in) {};

    double dumb();

    double relative();
};//test

#endif