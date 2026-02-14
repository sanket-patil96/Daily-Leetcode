class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> prevRow(1);
        prevRow[0] = double(poured);
        
        // go to 2nd row & onwords
        while(query_row--) {
            vector<double> currRow(prevRow.size()+1);
            int n = currRow.size();

            for(int i = 0; i < n; i++) {
                // take pours from left & above cols of above row

                // first handle corner glasses
                if(i == 0) {
                    if(prevRow[i] > 1)
                        currRow[i] += double(prevRow[i] - 1) / 2;     // it gets divided to 2 glasses from above row
                }
                else if(i == n-1) {
                    if(prevRow[i-1] > 1)
                        currRow[i] += double(prevRow[i-1] - 1) / 2;
                }
                // if both above glasses are available
                else {
                    if(prevRow[i] > 1) 
                        currRow[i] += double(prevRow[i] - 1) / 2; 

                    if(prevRow[i-1] > 1)
                        currRow[i] += double(prevRow[i-1] - 1) / 2;
                }
            }

            prevRow = currRow;
        }

        // check overflow on the query_glass, if yes then distribute it to its below one's
        if(prevRow[query_glass] > 1) 
            return 1;       // it is the max it can hold, after distribution
        
        return prevRow[query_glass];
    }
};