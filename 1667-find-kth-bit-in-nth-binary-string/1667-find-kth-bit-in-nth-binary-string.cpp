class Solution {
public:
    string invert(string bits) {
        string inversion = "";

        for(auto bit: bits) {
            inversion += (bit == '0') ? "1" : "0";
        }

        return inversion;
    }

    char findKthBit(int n, int k) {
        // do steps as given in example
        // first inversion of previous string 
        // then reverse it, and in for ith strign add prev + "1" + reversed string
        
        if(k == 1)
            return '0';

        string prev = "0";
        string curr = "";
        

        for(int i = 1; i < n; i++) {
            string inversion = invert(prev);
            reverse(inversion.begin(), inversion.end());
            curr = prev + "1" + inversion;
            prev = curr;
        }

        return prev[k-1];
    }
};