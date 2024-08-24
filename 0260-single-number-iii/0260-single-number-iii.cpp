class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // check notes tab & notebook
        int XOR = 0;

        for(auto i: nums)
            XOR ^= i;

        int i = 0;

        while((XOR & (1 << i)) == 0) 
            i += 1;
        // ith bit is different

        int num1 = 0;
        int num2 = 0;

        // group all the members according to their ith bit into different groups
        for(auto n: nums) {
            if ((n & (1 << i))) 
                num1 ^= n;
            else 
                num2 ^= n;
        }

        return {num1, num2};
    }
};