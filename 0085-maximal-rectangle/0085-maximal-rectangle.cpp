class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // this problem can be divided into largest rectangle in histogram
        // we can built a histogram of current array with addition of top array of it


        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        // this is single row of m coloms
        vector<int> histogram(m, 0);        // initially all 0's for 0th array in matrix

        for(int i = 0; i < n; i++) {
            // add current array with the previous histogram array, if ar[i] = 0 then keep 0 as it is without addition
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '0')
                    histogram[j] = 0;
                else
                    histogram[j] += 1;        // only 1 height can be add (coz binary matrix)
            }

            // now find largest rectange in the builded histogram prevArr
            ans = max(ans, largestRectangleInHistogram(m, histogram));
        }
        
        return ans;
    }

    int largestRectangleInHistogram(int n, vector<int> &heights) {
        vector<int> rightSmaller(n);
        vector<int> leftSmaller(n);
        nextSmaller(rightSmaller, heights, n);
        prevSmaller(leftSmaller, heights, n);
        
        // step2: calculate rectanlge are for each height
        int maxRectangle = 0;
        for(int i = 0; i < n; i++) {
            int area = (rightSmaller[i] - leftSmaller[i] - 1) * heights[i];
            maxRectangle = max(maxRectangle, area);
        }

        return maxRectangle;
    }

    void nextSmaller(vector<int> &rightSmaller, vector<int> heights, int n) {
        stack<int> s;           // monotic stack, (will store only indeices of increasing values, pop all values that are greater than current)
        rightSmaller[n-1] = n;  // there is no next element for last value
        s.push(n-1);

        for(int i = n-2; i >= 0; i--) {
            while(s.size() && heights[s.top()] >= heights[i])
                s.pop();
        
            rightSmaller[i] = s.empty() ? n : s.top();
            s.push(i);
        }
    }

    void prevSmaller(vector<int> &leftSmaller, vector<int> heights, int n) {
        stack<int> s2;
        leftSmaller[0] = -1;  // there is no previous element for first value
        s2.push(0);

        for(int i = 1; i < n; i++) {
            while(s2.size() && heights[s2.top()] >= heights[i])
                s2.pop();
        
            leftSmaller[i] = s2.empty() ? -1 : s2.top();
            s2.push(i);
        }
    }
};