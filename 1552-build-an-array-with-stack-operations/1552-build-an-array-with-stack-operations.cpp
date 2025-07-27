class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // simple logic: 
        // 1. push the current value from step to stack array
        // 2. if the pushed value not on target[cnt] then pop it
        // 3. if on target[cnt] then cnt++;

        // Without using stack array & more accurate: 
        //    Use “Push” for numbers to be kept in target array and [“Push”, “Pop”] for numbers to be discarded.

        vector<string> ans;
        int i = 1;
        int cnt = 0;     // to track values target 
        int m = target.size();

        // as in constrains target[i] <= n & target is in increasing order so
        // no need to check n we just need to run till last element of target
        
        while(i <= target[m-1]) {
            if(i == target[cnt]) {
                ans.push_back("Push");
                cnt++;
            }
            else {
                // since we don't need to add the ith value so 2 operations will required on stack push & pop
                ans.push_back("Push");
                ans.push_back("Pop");
            }

            i++;
        }

        return ans;
    }
};