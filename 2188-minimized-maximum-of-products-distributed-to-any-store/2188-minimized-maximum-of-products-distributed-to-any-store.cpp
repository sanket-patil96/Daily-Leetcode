class Solution {
public:
    int checkForDistribution(vector<int> arr, int targetCapacity) {
        // required stores to store the items till given capacity
        int stores = 0;

        for(auto i: arr) {
            int val = i/targetCapacity;
            // means, the number did not fully divide, means we need one more store to store remaining types
            // like exp: if i = 11 & capacity = 3 then 11/3 = 3, there remains 2 more quantities as 11 % 3 = 2, so one store extra for this
            if(i % targetCapacity != 0)
                val++;

            stores += val;
        }

        return stores;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        // we can try this using typical binary search approach
        // we can set high capacity of items distribution can be the highest items of type
        // and low can be the total sum of itmes/n 
        // so everytime, we set mid as targetCapacity that stores should  distribute the items 
        // if we can distribute the items to stores < n means the distribution is correct 
        // but we try to more minimize the no.of items pre shop
        // else we increase our low capacity to mid+1 if stores required more than give to distribute in given capacity

        // base case:
        // we have to give only 1 type of items to any store, so if types are more than store then it can't be done
        int m = quantities.size();
        if(n < m)
            return -1;

        int h = *max_element(quantities.begin(),  quantities.end());
        long long sum = accumulate(quantities.begin(), quantities.end(), 0LL);
        int l = ceil(float(sum)/n);
        // int l = 1;

        int ans = INT_MAX;

        while(l < h) {
            int mid = l + (h-l) / 2;

            int requiredStores = checkForDistribution(quantities, mid);

            if(requiredStores > n)
                l = mid+1;
            else {
                // means we can distribute the given items to given no.of stores, now try to more minimize items per store
                ans = mid;      
                h = mid;
            }
        }

        return h;       // or ans
    }
};