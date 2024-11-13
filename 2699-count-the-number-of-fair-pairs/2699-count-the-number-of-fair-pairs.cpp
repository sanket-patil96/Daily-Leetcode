class Solution {
public:

    int lowerSearch(vector<int>&nums, int s, int limit, int target) {
        int l = s;
        int h = nums.size()-1;
        int res = -1; 

        while(l <= h) {
            int mid = l + (h-l)/2;

            if(nums[mid] < target)
                l = mid+1;
            else if(nums[mid] <= limit){
                res = mid;
                h = mid-1;
            }
            else 
                h = mid-1;
        }

        return res;
    }

    int upperSearch(vector<int>&nums, int s, int min, int target) {
        int l = s;
        int h = nums.size()-1;
        int res = -1; 

        while(l <= h) {
            int mid = l + (h-l)/2;

            if(nums[mid] > target)
                h = mid-1;
            else if(nums[mid] >= min) {
                res = mid;
                l = mid+1;
            }
            else 
                l = mid+1;
        }

        return res;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // first sort the array
        // for each i start from i+1 and find the first(minimun after i) index that satisfy the criteria of addition >= lower && addition <= upper category
        // for each i start from i+1 and find the last(from end) index that satisfy the criteria of addition <= lower && addition >= upper category
        // add both counts to result count, & at last return it

        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long cnt = 0;
          
        // we want pairs so don't go till last index
        for(int i = 0; i < n-1; i++) {
            int lowerInd = lowerSearch(nums, i+1, upper-nums[i], lower-nums[i]);
            int upperInd = upperSearch(nums, i+1, lower-nums[i], upper-nums[i]);
            
            if(upperInd != -1 && lowerInd != -1)
                cnt += (upperInd-lowerInd + 1);
        }

        return cnt;
    }
};