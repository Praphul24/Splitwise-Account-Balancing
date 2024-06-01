#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include "../include/Transaction.h"
#include "../include/PersonalBalance.h"
#include "../include/PriorityQueueComparators.h"

using namespace std;

// Function to recursively backtrack through debts and settle balances
int dfsBackTrack(int start, vector<int>& debts) {
    // Skip zero balances
    while (start < debts.size() && debts[start] == 0) start++;

    // Base Case: All balances are settled
    if (start == debts.size()) return 0;

    // Initialize minimum transaction count to maximum possible value
    int minTCount = INT_MAX;

    // Try settling debts using other balances
    for (int i = start + 1; i < debts.size(); i++) {
        if ((debts[i] < 0 && debts[start] > 0) || (debts[i] > 0 && debts[start] < 0)) {
            // Try to settle debts[start] with debts[i]
            debts[i] += debts[start];
            // Recur for remaining balances after settling debts[start]
            minTCount = min(minTCount, 1 + dfsBackTrack(start + 1, debts));
            // Undo the settlement: backtracking
            debts[i] -= debts[start];
        }
    }
    return minTCount; // Return the minimum transaction count
}

// Function to simplify transactions using Optimal Account Balancing
int optimalAccountBalancing(const vector<Transaction>& transactions) {
    // Map to store individual balances
    unordered_map<string, int> balances;

    // Step 1: Calculate individual balances
    for (const auto& trans : transactions) {
        balances[trans.from] -= trans.amount; // Subtract amount from debtor's balance
        balances[trans.to] += trans.amount;   // Add amount to creditor's balance
    }

    // Create a vector of balances to simplify calculations
    vector<int> debts;
    for (auto& b : balances) {
        if (b.second != 0) debts.push_back(b.second); // Ignore zero balances
    }

    // Step 3: Settle debts using Depth-First Search with Backtracking
    return dfsBackTrack(0, debts);
}

// Main function
int main() {
    int nOT;
    cout << "Enter the number of transactions: ";
    cin >> nOT;

    // Input transactions
    vector<Transaction> transactions(nOT);

    cout << "Enter the transactions in the format [from, to, amount]:\n";
    for (int i = 0; i < nOT; ++i) {
        cin >> transactions[i].from;
        cin >> transactions[i].to;
        cin >> transactions[i].amount;
    }

    // Simplify transactions using Splitwise algorithm
    int optimal_nOT = optimalAccountBalancing(transactions);

    // Output simplified transactions
    cout << "Simplified transactions:\n";
    if(optimal_nOT==0){
        cout<<"No transactions needed.\n";
    }
    else{
        cout<<"Optimal No. of Transactions to settle all the debts: "<<optimal_nOT;
    }

    return 0;
}
