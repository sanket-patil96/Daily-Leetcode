class Solution {
public:

    bool isSorted(vector<int> &nums) {

        for(int i = 0; i < nums.size()-1; i++) 
            if(nums[i] > nums[i+1])
                return false;

        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        // use brute force:
        // check pairts in, [i]+[i+1] sum and get the i of min sum
        // erase the pair, ind at place of i, insert their sum
        // do this till array is unsorted
        
        int cnt = 0;
        
        while(true) {
            // check if array become sorted
            if(isSorted(nums))
                return cnt;
            
            int minSum = INT_MAX;
            int minPair = 0;   // index of min-sum pair
            for(int i = 0; i < nums.size()-1; i++) {
                if(minSum > nums[i]+nums[i+1]) {
                    minSum = nums[i]+nums[i+1];
                    minPair = i;
                }
            }

            // now remove the pair and insert sum
            nums.erase(nums.begin()+minPair, nums.begin()+minPair+2);
            nums.insert(nums.begin()+minPair, minSum);
            cnt++;
        }

        return cnt;
    }
};