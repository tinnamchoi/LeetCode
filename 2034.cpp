/* Stock Price Fluctuation */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class StockPrice {
public:
    unordered_map<int, int> prices;
    int latest = 0;

    StockPrice() {}
    
    void update(int timestamp, int price) {
        prices[timestamp] = price;
        if (timestamp > latest) {
            latest = timestamp;
        }
    }
    
    int current() {
        return prices[latest];
    }
    
    int maximum() {
        int max = 0;
        for (auto i : prices) {
            if (i.second > max) {
                max = i.second;
            }
        }
        return max;
    }
    
    int minimum() {
        int min = INT_MAX;
        for (auto i : prices) {
            if (i.second < min && i.second != 0) {
                min = i.second;
            }
        }
        return min;
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