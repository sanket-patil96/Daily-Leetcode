class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // same as: 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

        int n = hand.size(); 
        sort(hand.begin(), hand.end());

        unordered_map<int, int> mp;
        for(int i: hand) 
            mp[i]++;

        for(int i: hand) {
            if(mp[i] == 0)    continue;       // means current element already got picked in previous set

            for(int cnt = 0; cnt < groupSize; cnt++) {
                if(mp[i+cnt] == 0) return false;        // decrese freq. as we used it in this set
                mp[i+cnt]--;    
            }
        }

        return true; 
    }
};