class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // there is a pattern in this problem (see in the notion)
        // We want to find a larger number, but not too large - just the next larger one =>
        // We want to avoid chaning the number in the left - it will increase the number too much =>
        // Example: 4325413 -> we can only change the last two numbers and have 432531
        // What if it was 432531 in the first place? 31 cannot be increased.
        // Lets try 531 - still no
        // 2531 - this can be incrased - the smallest number that can be used to incrase the 2 is 3. so for now we have 3521.
        // Next we want to minimize 3521 - thats easier - just sort the numbers to the right of 3 - 3125. So the unswer is 4323125

        // ex: 154320
        // step1: find the first number from right that decline (in exp, here 1 is the one that decline from right others are increasing from right)
        // step2: find the greatest number that declining number from right if i>=0, (in exp its 2)
        // step3: sort the number from i+1 to n-1 to make the smallest number (or reverse as they are in decreasing order)

        int n = nums.size();

        // step1
        int i = n-2;
        while(i >= 0 && nums[i] >= nums[i+1])
            i--;
        
        // step2, the first number from right that has greater value than nums[i] is the most small greater as number from right are in increasing order to left
        if(i >= 0) {
            int j = n-1;
            while(nums[j] <= nums[i])
                j--;

            swap(nums[j], nums[i]);
        }

        // now reverse works even if i= -1 as we are reversing from i+1 to last, coz at i there is the next greater value
        reverse(nums.begin()+i+1, nums.end());
    }
};