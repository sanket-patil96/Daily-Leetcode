class Solution {
public:
    int bestClosingTime(string customers) {
        // use suffix sum for finding penalties if shop closed at current time

        int n = customers.size();

        // if there is no N means shop should close at ending
        if(customers.find('N') == string::npos)
            return n;
        

        // suffix array shows penalties if closed at i'th time
        vector<int> suffPenalty(n);     
        int penalties = 0;

        for(int i = n-1; i >= 0; i--) {
            if(customers[i] == 'Y')         // penalty if closed today
                penalties++;
            
            suffPenalty[i] = penalties;
        }

        // now check the 'earliest' time where penalties are less
        int minPenalty = INT_MAX;     // assign with highest penalty
        int closeTime = n;
        int penaltyTillNow = 0;           // also need to calcuate penalties occur till now

        for(int i = 0; i < n; i++) {

            if(minPenalty > penaltyTillNow + suffPenalty[i]) {
                minPenalty = penaltyTillNow + suffPenalty[i];
                closeTime = i;
            }

            // if shop not closing today then this should be a penalty
            if(customers[i] == 'N')
                penaltyTillNow++;
        }

        // need to consider if closed at nth day 
        if(minPenalty > penaltyTillNow) {
            // no need of updating penalty, coz no more iterations further
            closeTime = n;
        }

        return closeTime;
    }
};