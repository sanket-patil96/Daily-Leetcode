class Solution {
public:
    int countOdds(int low, int high) {
        // don't need to traverse, odd & evens are always half in any given range
        // if low is the odd & it has even numbers after it, then odd count from that is (afterElementsCnt/2 + 1(for low))
        // if low is odd and odd nums are there after it, then odd cnt = afterElementCnt / 2
        int cnt = 0;

        if(low % 2 != 0 || high % 2 != 0)
            cnt = 1;

        cnt += ((high-low) / 2);

        return cnt;
    }
};