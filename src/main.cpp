#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include "../include/Transaction.h"
#include "../include/PersonalBalance.h"
#include "../include/PriorityQueueComparators.h"

using namespace std;

// Function to simplify transactions using Splitwise algorithm
vector<Transaction> splitwiseAlgo(const vector<Transaction>& transactions) {
    vector<Transaction> simplified;

    // Priority queues to store positive and negative balances
    priority_queue<PersonalBalance, vector<PersonalBalance>, CompareBalance> positives;
    priority_queue<PersonalBalance, vector<PersonalBalance>, CompareBalance> negatives;

    // Map to store individual balances
    unordered_map<string, int> balances;

    // Step 1: Calculate individual balances
    for (const auto& trans : transactions) {
        balances[trans.from] -= trans.amount; // Subtract amount from debtor's balance
        balances[trans.to] += trans.amount;   // Add amount to creditor's balance
    }

    // Step 2: Separate positive and negative balances into priority queues
    for (const auto& nameBalance : balances) {
        string name = nameBalance.first;
        int balance = nameBalance.second;
        if (balance > 0)
            positives.push(PersonalBalance(name, balance));
        else if (balance < 0)
            negatives.push(PersonalBalance(name, balance));
    }

    // Step 3: Settle debts using greedy approach
    while (!positives.empty() && !negatives.empty()) {
        auto max_pos = positives.top();
        positives.pop();
        auto max_neg = negatives.top();
        negatives.pop();

        // Determine the amount to be settled
        int payment = min(abs(max_pos.balance), abs(max_neg.balance));

        // Create a simplified transaction and add it to the list
        simplified.push_back({max_neg.name, max_pos.name, payment});

        // Update balances after the transaction
        max_pos.balance -= payment;
        max_neg.balance += payment;

        // Re-insert updated balances into the respective priority queues
        if (max_pos.balance > 0)
            positives.push(max_pos);
        if (max_neg.balance < 0)
            negatives.push(max_neg);
    }

    return simplified;
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
    vector<Transaction> simplified = splitwiseAlgo(transactions);

    // Output simplified transactions
    cout << "Simplified transactions:\n";

    if(simplified.empty()) cout<<"Transaction not needed, It's already Simplified\n";
    else{
        for (const auto& trans : simplified) {
        cout << trans.from << " -> " << trans.to << ": " << trans.amount << "\n";
        }
    }

    return 0;
}


