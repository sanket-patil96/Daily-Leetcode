class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // neive appraoch:
        // sort(nums.begin(), nums.end());

        // for(int i = 0; i < nums.size()-1; i++) {
        //     if(nums[i] == nums[i+1])
        //         return nums[i];
        // }

        // return -1;

        // efficient approach with XOR (**not working correctly!!)
        // this only works for assuming repeated elem repeats only 1 time
        // int ans = 0;

        // // XOR all elements in the array
        // for (int i = 0; i < nums.size(); i++) {
        //     ans ^= nums[i];
        // }

        // // XOR 1 to n
        // for (int i = 1; i <= nums.size(); i++) {
        //     ans ^= i;
        // }

        // return ans;


        // using fast & slow pointers time: O(n) space: O(1)
        int fast = nums[0];
        int slow = nums[0];

        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while(fast != slow);

        // now we again start fast from beginning and slow from where it is, then move both 
        // 1 step at time till they meet, meeting point is the duplicate number
        fast = nums[0];
        while(fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }

        return slow;
    }
};