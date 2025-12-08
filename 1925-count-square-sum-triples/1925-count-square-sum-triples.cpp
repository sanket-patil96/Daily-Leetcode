class Solution {
public:
    int countTriples(int n) {
        // brute force:
        // get all the squares of all numbers from 1 to n
        // then use 3 loops for finding such triples

        vector<long long> sqr(n+1, 0);
        for(int i = 1; i <= n; i++)
            sqr[i] = (long long)i*i;

        int cnt = 0;
        for(int i = 1; i <= n-2; i++) {
            for(int j = i+1; j <= n-1; j++) {
                for(int k = j+1; k <= n; k++) {
                    if(sqr[i]+sqr[j] == sqr[k])
                        cnt+=2; // for every possible pair their is its alternate also, like: (3,4,5) and (4,3,5).  here 3,4 & 4,3 both are counted
                }
            }
        }

        return cnt;
    }
};