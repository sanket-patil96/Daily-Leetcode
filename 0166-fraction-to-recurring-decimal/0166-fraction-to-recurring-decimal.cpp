class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)  return "0";

        string result;

        // handle sign
        // ^ is the bitwise XOR operator (here it works like logical XOR since the conditions yield true/false).
        // Meaning: push '-' only if exactly one of them is negative. 
        // if both are negative then answer will be positive i.e -2/-2 = 1
        if((numerator < 0) ^ (denominator < 0)) result.push_back('-');

        long num = labs((long) numerator);      // absolute value of long is labs()
        long den = labs((long) denominator);

        // integer part
        result += to_string(num / den);
        long remainder = num % den;                  // get the remaining part through reminder
        if(remainder  == 0)      return result;      // if perfect dividing the numerator

        // fraction part
        result.push_back('.');
        unordered_map<long,  int> mp;        // to store the reminders with indexes for finding repeting part

        while(remainder != 0) {
            if(mp.count(remainder))  {     // if there is repeating part, then insert brackets and return
                result.insert(mp[remainder], "(");       // push the opening bracket at starting index of repeting reminder
                result.push_back(')');

                return result;
            }

            mp[remainder] = result.size();   // store reminder and its index where it will be stored
            remainder *= 10;                  // same as we do long division
            result += to_string(remainder / den);
            remainder %= den;
        }

        return result;
    }
};