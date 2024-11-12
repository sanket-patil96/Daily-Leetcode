class Solution {
public:
    int searchQ(vector<vector<int>>& items, int q) {
        int n = items.size();
        int l = 0;
        int h = n-1;
        int ans = -1;

        while(l <= h) {
            int mid = l + (h-l)/2;

            if(items[mid][0] <= q) { 
                ans = items[mid][0];
                l = mid+1;
            }
            else 
                h = mid-1;
        }

        return ans;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // space: O(N)
        // we sort the items array based on the price of each item
        // then from 1 to n price store the max beauty till i'th item & assign it to its price in map
        // so when traversing queries if queries[i] = 5, then if map has 5 price item then we can get max beauty till price 5 
        // if queries[i] not present as price key in map, then we decrese the ith query value, coz it want price to be less equal query value, so we lower closer price present then we can get the answer for that query

        sort(items.begin(), items.end());
        unordered_map<int, int> mp;         // map of price & it's beauty
        int maxBeauty = INT_MIN;
        
        for(auto item: items) {
            maxBeauty = max(maxBeauty, item[1]);
            mp[item[0]] = maxBeauty;
        }

        vector<int> ans;
        for(auto q: queries) {
            // we have to use binary search here to check if closest value under q are present or not
            int res = searchQ(items, q);
            if(res == -1)
                ans.push_back(0);
                
            else 
                ans.push_back(mp[res]);
        }

        return ans;
    }
};