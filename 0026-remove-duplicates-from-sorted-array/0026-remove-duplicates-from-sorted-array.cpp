class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // check the current no. with previous, if equal maintain k on that index
        // next time if unique occured copy it to that index & do K++;

        // int k = 1;
        // for(int i = 1; i < nums.size(); i++)
        // {
        //     if(nums[i] != nums[i-1])
        //         nums[k++] = nums[i];
        // }

        // return k;




        // we check our previous number is same like current if not then replace nums[k] = nums[i]
        // and increment k if same then just do nothing
        int i = 1;      // can't compare nums[0] with previous
        int k = 1;      // start from 1 with i
        for(i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i-1])
                nums[k++] = nums[i];
        }

        return k;
    }
};