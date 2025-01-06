class Solution {
public:
    vector<int> minOperations(string boxes) {
        // try brute force from each box, TC: O(N^2)  SC: O(N)
        // find all 1's distances from i & add them in ans[i]
        int n = boxes.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j)  continue; 
                if(boxes[j] == '1') 
                    ans[i] += abs(j-i);
            }   
        }

        return ans;
    }
};