class Solution {
public:

    // check if all cars can get repaired in maxTime (parallel time, not the addition)
    bool canRepair(int cars, long long maxTime, vector<int> & ranks) {
        int totalRepairedCars = 0;

        for(int i = 0; i < ranks.size(); i++) {
            int taken = 1;
            while((long long)(ranks[i] * pow(taken, 2)) <= maxTime) 
                taken++;

            // add the repaired cars by ith rank mechanic
            totalRepairedCars += taken-1;
            if(totalRepairedCars >= cars)
                break;
        }

        // check if all cars are repaired under the maxTime 
        return totalRepairedCars >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        // case 1: what can be max minutes taken if there's only 1 mechanic (rank[i]*cars^2)
        // case 2: if there is single car then time will be the smallest time taker mechanic's time

        // Note: car are repaired simultaniously, so don't need to add the timings of all mechanics

        sort(ranks.begin(), ranks.end());
        int n = ranks.size();
        long long high = ranks[n-1] * pow(cars, 2);
        long long low = 1;
        long long ans = 0;

        while(low <= high) {
            // get the time for checking if all cars can repair within mid timing
            long long mid = low + (high - low) / 2;

            if(canRepair(cars, mid, ranks)) {
                high = mid - 1;
                ans = mid;
            }

            else 
                low = mid + 1;
        }

        return ans;
    }
};