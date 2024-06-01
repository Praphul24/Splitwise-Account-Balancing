#ifndef PRIORITYQUEUECOMPARATORS_H
#define PRIORITYQUEUECOMPARATORS_H

#include "PersonalBalance.h"

// Custom comparator for priority queue to prioritize positive and negative balances (max heap by absolute value)
struct CompareBalance {

    bool operator()(const PersonalBalance& a, const PersonalBalance& b) {
        return abs(a.balance) < abs(b.balance); // prioritize larger absolute values
    }
    
};


#endif // PRIORITYQUEUECOMPARATORS_H
