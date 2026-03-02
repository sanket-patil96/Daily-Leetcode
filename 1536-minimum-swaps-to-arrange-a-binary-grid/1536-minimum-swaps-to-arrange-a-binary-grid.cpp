class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        // we want all row cells after (i,i)th cell to be having value 0, then only its valid matrix
        // count the no.of trailing zeros, and next is similar to bubble sort on it
        
        // For a grid of size n, row i must have at least n - 1 - i trailing zeros
        // 1. First, count the number of trailing zeros in each row.
        // 2. For each position i, find the nearest row below that has enough trailing zeros.
        // 3. Bring that row up using adjacent swaps (like bubble sort).
        // 4. If no such row exists, return -1.
        // This greedy approach works because earlier rows have stricter requirements, so we fix them first using the closest valid row to minimize swaps.
        
        int n = grid.size();

        // create vector for count the trailing zeros in each row
        vector<int> trailingZeros(n);

        for(int i = 0; i < n; i++) {
            int cntTrailZeros = 0;       
            for(int j = n-1; j >= 0; j--) {
                if(grid[i][j] == 1)   break;     // break as soon as we find a '1'
                cntTrailZeros++;
            }

            trailingZeros[i] = cntTrailZeros;
        }

        // if current ith row don't have enough trailing zeros (require at least n-i-1 trailing zeros)
        // then find the nearest next row that satisfy the condition and count swaps
        int minSwaps = 0;

        for(int i = 0; i < n; i++) {
            int reqZeros = n-i-1;
            int foundAt = -1;     // index of satisying row

            if(trailingZeros[i] < reqZeros) {
                for(int j = i+1; j < n; j++) {
                    if(trailingZeros[j] >= reqZeros) {
                        foundAt = j;
                        break;
                    }
                }   

                if(foundAt == -1) 
                    return -1;          // as we can't make it valid matrix

                // bring that row till ith row by swaping
                for(int j = foundAt; j > i; j--) {
                    swap(trailingZeros[j], trailingZeros[j-1]);
                    minSwaps++;
                }
            }
        }

        return minSwaps;
    }
};