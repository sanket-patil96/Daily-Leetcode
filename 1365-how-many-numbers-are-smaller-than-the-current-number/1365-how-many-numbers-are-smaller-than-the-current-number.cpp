class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // best optimization using constraints
        // Frequency Count: We iterate through nums and increment the count at arr[nums[i]].
        // Example: If nums = [8,1,2,2,3], then arr[2] will be 2 because '2' appears twice.
        // Prefix Sum: We iterate through the frequency array and add the value of the previous index to the current one.
        // Logic: After this, arr[i] contains the total count of all numbers less than or equal to i.
        // Mapping Results: For each number in the original nums array, the count of elements smaller than it is stored at arr[nums[i]-1].
        // Edge Case: For nums[i] == 0, there are no numbers smaller than it, so we simply push 0.

        // Complexity
        // Time complexity: O(N)
        // Space complexity: O(1)

        int arr[101] = {0};
        vector<int> ans;

        for (int a = 0; a < nums.size(); a++)
            arr[nums[a]]++;

        for (int a = 1; a < 101; a++)
            arr[a] += arr[a - 1];

        for (int a = 0; a < nums.size(); a++) {
            if (nums[a] == 0)
                ans.push_back(0);
            else
                ans.push_back(arr[nums[a] - 1]);
        }
        return ans;
    }
};