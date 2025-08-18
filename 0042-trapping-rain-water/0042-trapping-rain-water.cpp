class Solution {
public:
    int trap(vector<int>& height) {
        // we only need to care about how much water can be trapped above current spot
        // by checking the building sizes of left & right sides
        // and doing this for all spots will give us total trapped water

        int n = height.size();

        vector<int> leftLargest(n, 0);
        vector<int> rightLargest(n, 0);

        getLeftMax(n, height, leftLargest);
        getRightMax(n, height, rightLargest);

        int totalWater = 0;
        for(int i = 0; i < n; i++) {
            // get the min height from both sides
            int minHeight = min(leftLargest[i], rightLargest[i]);
            totalWater += minHeight <= height[i] ? 0 :  minHeight - height[i];
        }

        return totalWater;
    }

    void getLeftMax(int n, vector<int> &ar, vector<int> &ans) {
        // we use monotonic increasing stack
        stack<int> s;
        s.push(ar[0]);      // for first don't need to check its left

        for(int i = 1; i < n; i++) {
            while(s.size() && s.top() <= ar[i])
                s.pop();
            
            if(s.empty())   
                s.push(ar[i]);
            else            
                ans[i] = s.top();
        }
    }

    void getRightMax(int n, vector<int> &ar, vector<int> &ans) {
        // we use monotonic decreasing stack
        stack<int> s;
        s.push(ar[n-1]);      // for last don't need to check its right

        for(int i = n-2; i >= 0; i--) {
            // if current is max from right
            while(s.size() && s.top() <= ar[i]) 
                s.pop();
        
            if(s.empty())    
                s.push(ar[i]);
            else            
                ans[i] = s.top();
        }
    }
};