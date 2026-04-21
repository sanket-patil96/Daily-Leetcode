class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // we can create adjacency list of managers with their subordinates
        // create queue that will store the {employee, thatEmployeeTimeToInformSubordinates}
        // first we push head  with time=0, as news gets to it at 0th minute
        // then till !q.empty(), get the manager/employee and its arrival time of new to it, 
        // visit the subordinates of it with the time that it newsArrivalTime + ItsRequiredTimeToInformOthers
        // and from that all process we store the timing which is greater(minutes require the news to rech last employee)
        
        vector<vector<int>> adj(n);
        for(int i = 0; i < manager.size(); i++) {
            if(i == headID)     continue;       // there is no manager of company-head 
            adj[manager[i]].push_back(i);
        }

        // queue contains {employee, theirInformedTime}
        queue<pair<int, int>> q;
        
        // now start from the head node
        q.push({headID, 0});        // head gets the new first (0th time)

        int maxTime = INT_MIN;
        while(!q.empty()) {
            int manager = q.front().first;
            int timeGets = q.front().second;        // the time when the news arrives to this manager
            q.pop();

            maxTime = max(maxTime, timeGets);

            // now tell all subordinations of it
            for(auto v: adj[manager]) {
                q.push({v, informTime[manager]+timeGets});   // it is the time that news arrives to 'v' employee
            }
        }

        return maxTime;
    }
};