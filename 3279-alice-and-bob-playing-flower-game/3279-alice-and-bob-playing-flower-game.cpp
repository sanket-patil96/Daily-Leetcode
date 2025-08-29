class Solution {
public:
    long long flowerGame(int n, int m) {
        // if the number of flowers combined in both lanes are odd then 
        // always alice will pick the last flower and win the game

        // if current no.of flowers in 1 len is odd then in next lane we must
        // choose even numbers so total will become odd flowers, and alice will win

        // if the max no. in 2nd lane is odd (m is odd) then there are 
        // max m/2+1 odds and m/2 are evens
        // and if m is even then both odd & evens are m/2

        long long ans = 0;
        return (long long)m * n / 2;;
    }
};