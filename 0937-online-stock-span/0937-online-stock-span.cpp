class StockSpanner {
private:
    stack<pair<int, int>> stocks;       // for price, count of lesser values before

public:
    StockSpanner() {
        // optimised: using stack
        // what we really want to count is that no.of smaller values appered before
        // so we use stack to store the values, if top value is greater than current value
        // then we have no span beyond 1, but if there are some values lesser than current value then count them while poping
        // and store the currnent value with its count as these values was lesser than current
        // so next time any value comes it doesn't have to go through all the values it can just get the count of top value span and add it to current value's span
    }
    
    int next(int price) {
        int span = 1;       // initially 1 for current price

        while(!stocks.empty() && stocks.top().first <= price) {
            span += stocks.top().second;    // get the count of this 
            stocks.pop();
        }

        stocks.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */