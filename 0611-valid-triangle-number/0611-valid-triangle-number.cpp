class Solution {
public:

    // this will return no. of conmbinations that can get triangle

    int isPair(vector<int>& nums, int ind) {
        int i = 0;
        int j = ind - 1;
        int cnt = 0;

        while(i < j) {
            if(nums[i] + nums[j] > nums[ind]) {
                cnt += j-i;     // (j-i) between all will also be possible
                j--;
            }
            else
                i++;
        }

        return cnt;
    }


    // for making triangle first 2 side length > 3rd side
    int triangleNumber(vector<int>& nums) {
        // i will try the approach of triplet sum where i try to find 
        // if there is pair > target
        // to use this appraoch of two pointers we have to sort array
        sort(nums.begin(), nums.end());

        int cnt = 0;

        // as first 2 we dont consider coz triangle require 3 sides so start from [2]
        for(int i = 2; i < nums.size(); i++) {
            cnt += isPair(nums, i);
        }

        return cnt;
    }
};