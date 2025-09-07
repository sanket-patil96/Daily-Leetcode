class Solution {
public:
    string removeKdigits(string num, int k) {
        // to reduce the num, we must have to delete the elements from left to right
        // for this we can use stack, if left elements are bigger than current then we pop them
        // and after processing num, we have elements in increasing order in stack
        // so if still we can remove elements, then we remove from right side(top of stack) coz they are bigger

        // To avoid MLE we can use ans string as stack

        if(k == num.size())
            return "0";

        // create answer
        string ans = "";       // work like monotonic stack, store only in non-decreasing order from back side

        for(char c: num) {
            while(ans.size() && k && ans.back() > c) {
                ans.pop_back();
                k--;
            }

            if(ans.empty() && c == '0')      continue;       // we don't want leading zeros, so don't push when there are no elements before
            ans.push_back(c);
        }

        // after processing num check if still can we remove items
        // if yes then we now remove from last of num
        while(ans.size() && k) {
            ans.pop_back();
            k--;
        }

        return ans == "" ? "0" : ans;
    }
};