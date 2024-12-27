class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // this problem can be tackled with the next greater approach
        // we maintain a next greater value which store the gretest value that
        // we can have on right side(after minusing it's index with value) of it (including itself for left side)

        // we start traversing from end and check next greater for current i,
        // and after check ith index use ith index as 'j' for left side elems, if current (value[j]-j) is greater than maxRight, if yes then update maxRight variable
        
        int n = values.size();
        int maxScore = INT_MIN;
        
        int maxRight = values[n-1]-(n-1);     // last doesn't have next elem to check  so start from n-2
        for(int i = n-2; i >= 0; i--) {
            maxScore = max(maxScore, values[i]+i+maxRight);

            if(values[i]-i > maxRight)
                maxRight = values[i]-i;
        }
        
        return maxScore;
    }
};