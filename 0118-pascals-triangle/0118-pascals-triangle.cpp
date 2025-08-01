class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // facts to know for solving the problem:
        // 1. on every next row there will be addition of 1 element in the row than previous
        // 2. every row's first and last value is 1
        // 3. to get the current value of jth index, we require addition of previous row's 
        //    j-1th value + jth value (consider edge cases where j=0 || j=n-1)
        
        vector<vector<int>> ans;
        // push first row initially
        ans.push_back({1});

        for(int i = 2; i <= numRows; i++) {
            vector<int> prevRow = ans.back();
            int currRowSize = i;

            vector<int> arr(currRowSize);
            arr[0] = 1, arr[currRowSize-1] = 1;        // edges
            for(int j = 1; j < currRowSize-1; j++)
                arr[j] = prevRow[j-1] + prevRow[j];

            ans.push_back(arr);
        }
        
        return ans;
    }
};