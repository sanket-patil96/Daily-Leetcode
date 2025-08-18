class Solution {
public:
    int trap(vector<int>& height) {
        // we only need to care about how much water can be trapped above current spot
        // by checking the building sizes of left & right sides
        // and doing this for all spots will give us total trapped water

        int n = height.size();

        vector<int> leftLargest(n), rightLargest(n);
        leftLargest[0] = height[0];
        rightLargest[n-1] = height[n-1];

        // we use leftLargest array itself to check the max one, from current and last
        for(int i = 1; i < n; i++) {
            leftLargest[i] = max(leftLargest[i-1], height[i]);
        }

        // same thing here
        for(int i = n-2; i >= 0; i--) {
            rightLargest[i] = max(rightLargest[i+1], height[i]);
        }
        

        int totalWater = 0;
        for(int i = 0; i < n; i++) {
            // get the min height from both sides
            int minHeight = min(leftLargest[i], rightLargest[i]);
            totalWater += minHeight <= height[i] ? 0 :  minHeight - height[i];
        }

        return totalWater;
    }
};