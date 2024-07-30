
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // optimising code
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        
        // time: O(N)
        // we keep track of min value till now, and calculate profit from every day & maximize it
        int mxProfit = 0;
        int mnDay = INT_MAX;

        for(int i = 0; i < prices.size(); i++)
        {
            mnDay = min(mnDay, prices[i]);
            mxProfit = max(mxProfit, prices[i]-mnDay);
        }
        
        return mxProfit;



        // using Min Heap:  T/C: O(N * LogN)      
        // we use min heap to store stock prices, every day we check if top value of heap
        // is lesser then we check maxProfit & go further
        // if current day has less price then top value then push it in min heap

        // priority_queue<int, vector<int>, greater<int>> pq;
        // pq.push(prices[0]);
        // int mxProfit = 0;

        // for(int i = 1; i < prices.size(); i++) {
        //     if(prices[i] < pq.top())
        //         pq.push(prices[i]);
        //     else 
        //         mxProfit = max(mxProfit, prices[i]-pq.top());
        // }

        // return mxProfit;

    }
};