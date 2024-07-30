class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 3rd method using *3 pointers (see notes tab)

        int low = 0, high = nums.size() - 1, i = 0;

        while (i <= high) {

            if (nums[i] == 0)
                swap(nums[i++], nums[low++]);

            else if (nums[i] == 1)
                i++;

            else
                swap(nums[i], nums[high--]);
        }
    }
};