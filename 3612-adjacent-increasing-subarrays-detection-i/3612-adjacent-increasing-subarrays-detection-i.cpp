class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        // brute for approach:
        // start checking each consecutive  subarrays
        // if any subarrays element don't follow the rule then break the current subarray check

        int n = nums.size();

        for(int i = 0; i < n; i++) {    // we only traverse till 'last' first-subarray's start, so it can complete with all k elements in its consecutive subarray wihtout our of bound error
            int j, x = i+k+1;                  // go on second value of subarray so we can compare with previous one
            for(j = i+1; j < i+k; j++) {
                if(j >= n || nums[j] <= nums[j-1] || x >= n || nums[x] <= nums[x-1])
                    break;
                x++;
            }

            // if subarray get completely traversed then it means we found the subarray
            if(j == i+k) {
                cout << j;
                return true;
            }
        }

        return false;
    }
};