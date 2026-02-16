/*QUESTION:You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

#include <stdio.h>

int maxProfit(int prices[], int n) {
    if (n == 0) return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];   // Update minimum price
        } else {
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit; // Update maximum profit
            }
        }
    }

    return maxProfit;
}

int main() {
    int n;
    scanf("%d", &n);

    int prices[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    printf("%d\n", maxProfit(prices, n));

    return 0;
}

 
