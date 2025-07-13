class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // brute force: 
        // 1.sort both arrays
        // 2. start trainer index i from 0, for each player check if ith trainer can has ability to train the player
        //    if yes then move both ith pointer and player for next checking & keep the count

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end()); 

        int i = 0;      // to track trainer
        int n = trainers.size();
        int matches = 0;

        for(auto p: players) {
            // skip the low ability trainers
            while(i < n && trainers[i] < p)
                i++;
            
            if(i == n)
                break;
            
            // means we found a match in above check
            matches++;
            i++;        // this trainer is assigned now
        }

        return matches;
    }
};