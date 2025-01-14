class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // we start from i = 0 to n, we use a set that tell us wheather a current value previously occured or not
        // at each step if the current value of A[i] OR B[i] has occured then we increment the count of mathes in that particulat level of i
        // if not already added then we add them in set
        // at last we add the current level count of matches to the total count that we previously found

        
        unordered_map<int, int> freq;
        unordered_set<int> s;
        vector<int> ans(A.size());
        int total_match = 0;

        for(int i = 0; i < A.size(); i++) {
            int cnt = 0;
            if(A[i] == B[i]) {
                cnt += 1;
                s.insert(A[i]);
            }
            else {
                if(s.count(A[i]))
                    cnt++;
                else
                    s.insert(A[i]);

                if(s.count(B[i]))
                    cnt++;
                else 
                    s.insert(B[i]);
            }

            ans[i] = total_match+cnt;
            total_match+=cnt;
        }

        return ans;
    }
};