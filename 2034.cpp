/* Stock Price Fluctuation */

#include <bits/stdc++.h>

using namespace std;

/* Submission */



class StockPrice {
public:
    unordered_map<int, int> prices;
    int latest = 0;
    int max = 0;
    int min = INT_MAX;
    int maxtime = 0;
    int mintime = 0;

    StockPrice() {}
    
    void update(int timestamp, int price) {
        prices[timestamp] = price;
        if (timestamp > latest) {
            latest = timestamp;
        }
        if (timestamp == maxtime && price < max) {
            max = 0;
            for (auto i : prices) {
                if (i.second > max) {
                    maxtime = i.first;
                    max = i.second;
                }
            }
        }
        if (price > max) {
            maxtime = timestamp;
            max = price;
        }
        if (timestamp == mintime && price > min) {
            min = INT_MAX;
            for (auto i : prices) {
                if (i.second < min) {
                    mintime = i.first;
                    min = i.second;
                }
            }
        }
        if (price < min) {
            mintime = timestamp;
            min = price;
        }
    }
    
    int current() {
        return prices[latest];
    }
    
    int maximum() {
        return prices[maxtime];
    }
    
    int minimum() {
        return prices[mintime];
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */