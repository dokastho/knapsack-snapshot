#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <iostream>
#include <vector>

using namespace std;

vector<size_t> mergesort(vector<size_t> items) {
    if (items.size() == 1)
    {
        if (items.back() < items.front())
        {
            swap(items.front(), items.back());
        }
        return items;
    }

    size_t middle = items.size() / 2;

    vector<size_t>::iterator middleIter(items.begin());
    advance(middleIter, middle);

    vector<size_t> first(items.begin(),middleIter);
    vector<size_t> second(middleIter,items.end());

    vector<size_t>::iterator fiter = first.begin();
    vector<size_t>::iterator siter = second.begin();
    items.clear();

    while (fiter != first.end() && (siter != second.end()))
    {
        if (*fiter < *siter)
        {
            items.push_back(*fiter);
            fiter++;
        }
        else {
            items.push_back(*siter);
            siter++;
        }
    }
    return items;
}

class knapsack {
    double cap;
    vector<size_t> items;
    
    public:

    knapsack(double cap_in, vector<size_t> items_in) : cap(cap_in), items(items_in) {};

    double dumb();

    double relative();
};

#endif