#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <iostream>
#include <vector>

using namespace std;

void mergesort(vector<pair<double,pair<size_t,size_t>>> &items) {
    
    if (items.size() == 2)
    {
        if (items.back().second.first < items.front().second.first)
        {
            swap(items.front(), items.back());
        }
        return;
    }

    size_t middle = items.size() / 2;

    vector<pair<double,pair<size_t,size_t>>>::iterator middleIter(items.begin());
    advance(middleIter, middle);

    vector<pair<double,pair<size_t,size_t>>> first(items.begin(),middleIter);
    vector<pair<double,pair<size_t,size_t>>> second(middleIter,items.end());

    mergesort(first);
    mergesort(second);

    vector<pair<double,pair<size_t,size_t>>>::iterator fiter = first.begin();
    vector<pair<double,pair<size_t,size_t>>>::iterator siter = second.begin();
    items.clear();

    while ((fiter != first.end()) & (siter != second.end()))
    {
        if (fiter->second.first < siter->second.first)
        {
            items.push_back(*fiter);
            fiter++;
        }
        else {
            items.push_back(*siter);
            siter++;
        }
    }
    while (fiter != first.end())
    {
        items.push_back(*fiter);
        fiter++;
    }
    while (siter != second.end())
    {
        items.push_back(*siter);
        siter++;
    }
    return;
}
void mergesort_ratio(vector<pair<double,pair<size_t,size_t>>> &items) {
    
    if (items.size() == 2)
    {
        if (items.back().first > items.front().first)
        {
            swap(items.front(), items.back());
        }
        return;
    }

    size_t middle = items.size() / 2;

    vector<pair<double,pair<size_t,size_t>>>::iterator middleIter(items.begin());
    advance(middleIter, middle);

    vector<pair<double,pair<size_t,size_t>>> first(items.begin(),middleIter);
    vector<pair<double,pair<size_t,size_t>>> second(middleIter,items.end());

    mergesort_ratio(first);
    mergesort_ratio(second);

    vector<pair<double,pair<size_t,size_t>>>::iterator fiter = first.begin();
    vector<pair<double,pair<size_t,size_t>>>::iterator siter = second.begin();
    items.clear();
    
    while ((fiter != first.end()) & (siter != second.end()))
    {
        if (fiter->first > siter->first)
        {
            items.push_back(*fiter);
            fiter++;
        }
        else {
            items.push_back(*siter);
            siter++;
        }
    }
    while (fiter != first.end())
    {
        items.push_back(*fiter);
        fiter++;
    }
    while (siter != second.end())
    {
        items.push_back(*siter);
        siter++;
    }
    return;
}


class knapsack {
    size_t cap;
    size_t current;
    size_t val;
    vector<pair<double,pair<size_t,size_t>>> items;
    public:

    knapsack(size_t cap_in, vector<pair<size_t,size_t>> items_in) : 
                    cap(cap_in), current(0), val(0) {
                        for (size_t i = 0; i < items_in.size(); i++)
                        {
                            items.push_back({(double)items_in[i].second / (double)items_in[i].first,
                                                {items_in[i].first, items_in[i].second}});
                        }
                        
                    };


    double ratio();

    double greedy();
};

knapsack generate_knapsack(size_t size) {
    vector<pair<size_t,size_t>> bag;
    for (size_t i = 0; i < size; i++)
    {
        bag.push_back({rand() % 16, rand() % 32});
    }
    knapsack k(128,bag);
    return k;
}

#endif