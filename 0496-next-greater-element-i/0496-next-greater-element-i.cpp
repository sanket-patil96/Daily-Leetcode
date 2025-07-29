class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // use suffix array to store the next greater element for each ith value of nums2, using stack
        // push every ith into stack even its smaller than top of stack coz for [1, 3, 4] max from right is 4 for all but for 1 there is 3 that is immediate max 
        // so if lets say [2, 5, 1, 3, 4]  at 5 pop all the smaller elemes from top of stack and at last  push the 5, so next time for 2 5 is max
        // use map to store the index of every element of nums2 to make ease the process of finding the nums1 value in nums2
        // traverse nums1 get the currosponding index of that elem in nums2 using map, use suffix array to get next greater

        int n = nums1.size();
        int m = nums2.size();

        vector<int> nextGreater(m);
        unordered_map<int, int> pos;
        stack<int> mxVal;

        // for last elem there is no next greater
        nextGreater[m-1] = -1;
        mxVal.push(nums2[m-1]);
        pos[nums2[m-1]] = m-1;

        for(int i = m-2; i >= 0; i--) {
            if(nums2[i] < mxVal.top()) {
                nextGreater[i] = mxVal.top();
            }
            else {
                // pop all small values 
                while(!mxVal.empty() && mxVal.top() < nums2[i])
                    mxVal.pop();
                
                // if stack empty means no bigger value of right of it, else store bigger
                if(mxVal.empty())
                    nextGreater[i] = -1;
                else 
                    nextGreater[i] = mxVal.top();
            }

            pos[nums2[i]] = i;
            mxVal.push(nums2[i]);
        }


        // main solution
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int ind = pos[nums1[i]];
            int greater = nextGreater[ind];

            ans.push_back(greater);
        }

        return ans;
    }
};