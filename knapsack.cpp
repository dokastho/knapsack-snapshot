#include "knapsack.h"

int main() {
    // run both types of greedy and return the better one
    // this works because both the dumb greedy and relatively greedy run in 
    // O(nLognLogC) time, so it's trivially 2O(nLognLogC)
    // C represents the capacity constraint in this context

    vector<pair<size_t,size_t>> vec;
    size_t capacity = 256;
    knapsack k(capacity,vec);

    double dumbVal = k.get_soln(true), relativeVal = k.get_soln(false);
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

double knapsack::get_soln(bool dumb) {
    mergesort(items,dumb)[0];
    int head = 0;
    while ((current < cap) && (head < items.size()))
    {
        val += items[head].second.second;
        current += items[head].second.first;
        head++;
    }
    return val;
}