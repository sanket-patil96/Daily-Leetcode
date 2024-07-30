class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // updated solution of Min Heap:  T/C: O(N) S/C: O(1)
        // we can optimise the min heap solution using simple 'mini' variable which will store 
        // the min stock price till now, we just update it when we see again new min value
        // also update when we sell that min stock then new min value will be current dat stock price
        
        int mxProfit = 0;
        int mini = prices[0];
        
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < mini) {
                mini = prices[i];
            }
            else {
                mxProfit += (prices[i]-mini);
                mini = prices[i];
            }
        }

        return mxProfit;
    }
};