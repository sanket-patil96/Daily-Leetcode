class Solution {
public:
    int searchQ(vector<vector<int>>& items, int q) {
        int n = items.size();
        int l = 0;
        int h = n-1;
        int ans = 0;

        while(l <= h) {
            int mid = l + (h-l)/2;

            if(items[mid][0] <= q) { 
                ans = max(ans, items[mid][1]);
                l = mid+1;
            }
            else 
                h = mid-1;
        }

        return ans;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Let M be the size of items and let N be the size of queries.
        // Time Complexity: O((M+N)⋅logM) 
        // space: O(logM)
        // we sort the items array based on the price of each item
        // then from 1 to n price store the max beauty till i'th item & assign it to its price in map
        // so when traversing queries if queries[i] = 5, then if map has 5 price item then we can get max beauty till price 5 
        // if queries[i] not present as price key in map, then we decrese the ith query value, coz it want price to be less equal query value, so we lower closer price present then we can get the answer for that query

        // now instead of using map we just modify the items array after sorting it and assign each item max beauty seen so far
        // so in binary search function we can directly get the max beauty for any query

        sort(items.begin(), items.end());
        int maxBeauty = INT_MIN;
        
        // update the items array for beauties 
        for(int i = 0; i < items.size(); i++) {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        vector<int> ans;
        for(auto q: queries) {
            // we have to use binary search here to check if closest value under q and its beauty
            ans.push_back(searchQ(items, q));
        }

        return ans;
    }
};