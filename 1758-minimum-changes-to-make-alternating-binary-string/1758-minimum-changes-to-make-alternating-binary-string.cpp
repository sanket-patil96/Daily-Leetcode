class Solution {
public:
    int minOperations(string s) {
        // either keep start with 0 or with 1, means pattern can be 0101 or 1010,
        // if it doesn't following the patter then change bits accordingly and count the changes
        // take min changes Count from starting with 0 OR 1

        int start0Changes = 0, start1Changes = 0;

        // starting with 0: whener flag is true there should be 0
        bool flag = true;       
        for(char c: s) {
            if((c == '1' && flag) || (c == '0' && !flag))        
                start0Changes++;
            flag = !flag;       // alternate flag on every index
        }

        // starting with 1: whenever flag is true there should be 1
        flag = true;       
        for(char c: s) {
            if((c == '1' && !flag) || (c == '0' && flag))        
                start1Changes++;
            flag = !flag;
        }

        return min(start0Changes, start1Changes);
    }
};