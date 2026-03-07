class Solution {
public:
    int minFlips(string s) {
        // there can be only 2 possible patterns: 1. '0101' 2. '1010'
        // try to find flips needed in both and take the min answer from it
        // to use the type 1 operation, we can concatenate s with itself, it will give all possible options
        // 

        int start0 = 0, start1 = 0;

        for(int i = 0; i < s.size(); i++) {
            if(i % 2 == 0) {
                if(s[i] != '0')
                    start0++;
                else
                    start1++;
            }
            else {
                if(s[i] != '1')
                    start0++;
                else
                    start1++;
            }
        }

        // now concatenate s += s, and keep window size of n (oroginal s size, 
        // and for left bits outside window, remove their counts from flips, if they were flipped
        int n = s.size();       // original string size
        int end = n;   // new ending point (starting of appended s)
        int st = 0; 
        s += s;

        int mini = min(start0, start1);

        while(end < s.size()) {
            // remove flips for starting
            if(end - st >= n) {
                if(st % 2 == 0) {
                    if(s[st] != '0')
                        start0--;
                    else
                        start1--;
                }
                else {
                    if(s[st] != '1')
                        start0--;
                    else
                        start1--;
                }

                st++;           // at a time only 1 element get added to window,  so only 1 element can go out of window, so no while loop needed 
            }

            if(end % 2 == 0) {
                if(s[end] != '0')
                    start0++;
                else
                    start1++;
            }
            else {
                if(s[end] != '1')
                    start0++;
                else
                    start1++;
            }

            end++;

            // update answer  on each new window
            mini = min({mini, start0, start1});
        }

        return mini;
    }
};