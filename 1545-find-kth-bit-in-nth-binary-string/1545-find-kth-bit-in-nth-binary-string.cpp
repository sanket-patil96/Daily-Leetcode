class Solution {
public:
    char findKthBit(int n, int k) {
        // simple logic, simulate as given
        // 1. in each step calculate new string as prev + "1" + reverse(invert(prev string))
        // 2. at last return the kth bit from final string

        string prev = "0";      // this  will keep track of previous binary string
        string newStr = "";

        while(n--) {
            newStr = prev + "1" + reverseInvert(prev);
            prev = newStr;      // now it will be previous for next operation
        }

        // now extract the kth bit from final string
        return prev[k-1];
    }

    string reverseInvert(string s) {
        // first invert the string
        string invert = "";

        for(char c: s) {
            if(c == '1')    invert += "0";
            else            invert += "1";
        }

        reverse(invert.begin(), invert.end());
        return invert;
    }
};