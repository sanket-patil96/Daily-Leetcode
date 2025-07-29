class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // use suffix array to store the next greater element for each ith value of nums2, using stack
        // push every ith into stack even its smaller than top of stack coz for [1, 3, 4] max from right is 4 for all but for 1 there is 3 that is immediate max 
        // so if lets say [2, 5, 1, 3, 4]  at 5 pop all the smaller elemes from top of stack and at last  push the 5, so next time for 2 5 is max
        // use map to store the index of every element of nums2 to make ease the process of finding the nums1 value in nums2
        // traverse nums1 get the currosponding index of that elem in nums2 using map, use suffix array to get next greater

        // \U0001f4a1 NOTE: little modification, just store the next greate on map itself usign stack, rather  than another suffix array
        int n = nums1.size();
        int m = nums2.size();

        // store next greater on map
        unordered_map<int, int> nextGreater;
        stack<int> mxVal;

        // for last elem there is no next greater
        mxVal.push(nums2[m-1]);
        nextGreater[nums2[m-1]] = -1;

        for(int i = m-2; i >= 0; i--) {
            int max = -1;

            if(nums2[i] < mxVal.top()) 
                max = mxVal.top();
            
            else {
                // pop all small values 
                while(!mxVal.empty() && mxVal.top() < nums2[i])
                    mxVal.pop();
                
                // if stack empty means no bigger value of right of it, else store bigger
                max = mxVal.empty() ? -1 : mxVal.top();
            }

            nextGreater[nums2[i]] = max;
            mxVal.push(nums2[i]);
        }


        // main solution
        vector<int> ans;
        for(int i: nums1) 
            ans.push_back(nextGreater[i]);
        

        return ans;
    }
};