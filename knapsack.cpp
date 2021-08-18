#include "knapsack.h"

int main() {
    // run both types of greedy and return the better one
    // this works because both the dumb greedy and relatively greedy run in 
    // O(nLognLogC) time, so it's trivially 2O(nLognLogC)
    // C represents the capacity constraint in this context

    srand((uint32_t)time(0));
    
    vector<pair<size_t,size_t>> vec;
    size_t bagSize = 256;
    knapsack k = generate_knapsack(bagSize);

    double dumbVal = k.greedy();
    double relativeVal = k.ratio();
    if (dumbVal < relativeVal)
    {
        cout << "Ratios were the best method with a winning score of " << relativeVal;
        cout << " compared to the greedy method with " << dumbVal << endl;
    }
    else {
        cout << "Greedy was the best method with a winning score of " << dumbVal;
        cout << " compared to the ratio method with " << relativeVal << endl;
    }
    return 0;
}

double knapsack::greedy() {
    items = mergesort(items);
    size_t head = 0;
    while ((current < cap) && (head < items.size()))
    {
        val += items[head].second.second;
        current += items[head].second.first;
        head++;
    }
    return (double)val;
}

double knapsack::ratio() {
    items = mergesort_ratio(items);
    size_t head = 0;
    while ((current < cap) && (head < items.size()))
    {
        val += items[head].second.second;
        current += items[head].second.first;
        head++;
    }
    return (double)val;
}