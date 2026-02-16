class Solution {
public:
    int reverseBits(int n) {
        // first convert to binary string
        // then reverse binary string  (don't require, coz in process of dividation we already store it in reversed order)
        // then retrive the integer from it

        string binary = "";

        // we have to take all 32 bints in binary sttring,  (leading zeros)
        for(int i = 0; i < 32; i++) {
            binary += (n % 2 == 0) ? '0' : '1';
            n /= 2;
        }

        cout << binary;

        int power = 0;
        int ans = 0;
        for(int i = binary.size()-1; i >= 0; i--) {
            if(binary[i] == '1')
                // ans += pow(2, power);
                ans += 1u << power;         // left shift to unsigned value
            power++;
        }

        return ans;
    }
};