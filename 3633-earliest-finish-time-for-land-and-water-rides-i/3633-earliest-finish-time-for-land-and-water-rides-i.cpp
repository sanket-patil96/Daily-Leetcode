class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // brute force:
        // just try each land slide with each water ride:

        int minTime = INT_MAX;
        
        for(int i = 0; i < landStartTime.size(); i++) {
            for(int j = 0; j < waterStartTime.size(); j++) {
                int rideTime, startRideEnd, endRideDur;

                if(landStartTime[i] < waterStartTime[j]) {
                    startRideEnd = landStartTime[i] + landDuration[i];
                    endRideDur = waterDuration[j];           // we only require the during of water ride to sum up it will landride

                    // also consider the gap between the rides to add it in total Time, like L = (5,3)  W = (9,4) total = 9+4 **not** 8+4
                    // so we don't need to start the next duration after completing land ride, we should consider from 9 (the time when W ride starts is > previous ride end)
                    if(startRideEnd < waterStartTime[j])
                        rideTime = waterStartTime[j] + endRideDur; 
                    else 
                        rideTime = startRideEnd + endRideDur;
                }
                else {
                    startRideEnd = waterStartTime[j] + waterDuration[j];
                    endRideDur = landDuration[i];   

                    if(startRideEnd < landStartTime[i])
                        rideTime = landStartTime[i] + endRideDur;
                    else 
                        rideTime = startRideEnd + endRideDur;
                }
                
                minTime = min(minTime, rideTime);  
            }
        }

        return minTime;
    }
};