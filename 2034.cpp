/* Stock Price Fluctuation */

#include <bits/stdc++.h>

using namespace std;

/* Submission */

class StockPrice {
public:
    vector<int> prices;

    StockPrice() {}
    
    void update(int timestamp, int price) {
        if (timestamp - 1 >= prices.size()) {
            prices.resize(timestamp, 0);
        }
        prices[timestamp - 1] = price;
    }
    
    int current() {
        return prices.back();
    }
    
    int maximum() {
        int max = 0;
        for (int i : prices) {
            if (i > max) {
                max = i;
            }
        }
        return max;
    }
    
    int minimum() {
        int min = INT_MAX;
        for (int i : prices) {
            if (i < min && i != 0) {
                min = i;
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