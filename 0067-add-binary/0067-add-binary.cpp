class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        string ans;
        int carry = 0;
        int sum = 0;

        while(i >= 0 || j >= 0) {

            sum = carry;  
            
            if(i >= 0) {
                sum += (a[i] - '0');   // to retrive int substract '0' from char
                i--;
            }
            
            if(j >= 0) {
                sum += (b[j] - '0');
                j--;
            }

            if(sum > 1) {
                ans += to_string(sum%2);    // store reminder (it can either 1 or 0, as dividing from 2)
                carry = 1;
            }
            else {          // means sum is 0
                carry = 0;
                ans += to_string(sum);
            }
        }

        // if carry remains
        if(carry == 1) 
            ans += "1";

        reverse(ans.begin(), ans.end());
        return ans;
    }
};