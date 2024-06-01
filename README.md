# Splitwise Algorithm Project

## Overview

This project implements a simplified version of the Splitwise algorithm to settle debts among multiple people using a greedy approach. The goal is to minimize the number of transactions required to balance all accounts or to have a minimum cash flow.

## Project Structure

Splitwise-application/
├── include/
│   ├── PersonBalance.h
│   ├── Transaction.h
│   └── PriorityQueueComparators.h
└── src/
    └── main.cpp


### File Summaries

#### Transaction.h
Defines the `Transaction` class, representing each transaction with a debtor, a creditor, and the transaction amount.

#### PersonBalance.h
Defines the `PersonalBalance` class, representing each person's balance (positive or negative).

#### PriorityQueueComparators.h
Defines custom comparator classes for priority queues to prioritize positive and negative balances based on their absolute values.

#### main.cpp
Integrates all components and implements the Splitwise algorithm to balance the accounts.


### High-Level Algorithm with Intuition

#### Steps:

**Input Transactions**:
   - The program starts by taking input transactions, where each transaction specifies a debtor, a creditor, and the amount.

1. **Calculate Individual Balances**:
   - For each transaction, update the balances of the involved individuals.
   - **Intuition**: By calculating net balances for each person, we can determine who owes money and who is owed money.
   - **Time Complexity**: O(n), where n is the number of transactions.

2. **Separate Positive and Negative Balances**:
   - Use priority queues to manage the balances:
     - One priority queue (max heap) for individuals with positive balances (creditors).
     - Another priority queue (max heap) for individuals with negative balances (debtors).
   - **Intuition**: By separating positive and negative balances, we can easily match the highest creditor with the highest debtor to settle the largest debts first.
   - **Time Complexity**: O(n log n) for building the priority queues.

3. **Settle Debts Using Greedy Approach**:
   - While there are still creditors and debtors:
     - Extract the individual with the highest positive balance from the positive queue.
     - Extract the individual with the highest absolute negative balance from the negative queue.
     - Determine the payment amount (minimum of the two balances).
     - Create a simplified transaction to settle this amount.
     - Update the balances of these two individuals.
     - If any balance remains after the settlement, re-insert the individual back into the appropriate priority queue.
   - **Intuition**: By always matching the largest creditor and debtor, we reduce the number of transactions needed to settle all debts.
   - **Time Complexity**: O(n log n) for managing the priority queues.

#### Overall Complexity:
- **Time Complexity**: O(n log n), where n is the number of transactions.
- **Space Complexity**: O(n), where n is the number of unique individuals involved in transactions.

## How to Compile and Run

1. **Compile the program**:
    ```sh
    g++ main.cpp -o main
    ```

2. **Run the program**:
    ```sh
    ./main
    ```

# TEST CASE
4
A B 10
C A 5
B A 1
B C 5

OUTPUT: A B 4

//4 transactions reduced to one






# Optimal Account Balancing (NP-HARD, EXPONENTIAL TC)

The algorithm works as follows:
1. **Calculate Balances**: First, it calculates the net balance for each individual, representing the amount they owe or are owed.
2. **Simplify Transactions**: It then tries to simplify the transactions by pairing individuals who owe each other money and settling their debts with the minimum number of transactions. This is achieved through a Depth-First Search (DFS) approach with backtracking.
3. **Output**: Finally, it outputs the simplified transactions or indicates if no transactions are needed.

## Time Complexity
- Calculating Balances: O(N), where N is the number of transactions.
- Simplifying Transactions (DFS): O(2^N), where N is the number of individuals with non-zero balances.
- In the worst case, the algorithm needs to explore all possible combinations of transactions.
  
Overall, the time complexity is dominated by the DFS step.

## Space Complexity
- Balances Calculation: O(N), where N is the number of unique individuals involved in the transactions.
- Simplifying Transactions: O(N), where N is the number of individuals with non-zero balances.
- We store the balances in a vector for simplicity during DFS.

In both cases, the space complexity is directly proportional to the number of unique individuals involved in the transactions.
