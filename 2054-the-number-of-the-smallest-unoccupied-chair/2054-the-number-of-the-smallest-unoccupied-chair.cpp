class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        // we have to sort friends by their arrival times but...
        // target friend is given by index so we can't change their order by sorting array,
        // but we can get targetFriend by first finding target node arrival(coz its unique), so we will know
        // which friend we have to target, we stop when we find chair for target friend

        // we use 2 mean heaps 
        // 1st for storing unoccupied chairs (it will be 0 to n-1)
        // 2nd for storing occupied chairs (will change  arroding to arrival & leaving time)

        // we store pair of {LeavingTime, occupiedChair} in 2nd heap of occupied chairs
        // so when leaving time is over we can pop chair and store it in unoccupied heap

        // as this there always smallest number chairs will be on top
        // and least leaving time freinds are on top in second heap

        // we use counter as arrival time of current friend, if from occupiedChairs 
        // any friend has less equal time of this counter than chairs will be free to use

        int targetFriendArrival = times[targetFriend][0];
        sort(times.begin(), times.end());
        int n = times.size();

        // store chairs in min heap
        priority_queue<int, vector<int>, greater<int>> unOccupiedChairs;
        for(int i = 0; i < n; i++)
            unOccupiedChairs.push(i);

        // store in form of {leaving, occupiedChair}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> OccupiedChairs;
        int cnt = 0;

        for(auto i: times) {
            // this count will be the current friends arrival time, it will be easy 
            // to pop friends who has leaving time less than this
            int arrival = i[0];
            cnt = arrival;

            // pop occuped chairs if timing is over
            while(!OccupiedChairs.empty() && OccupiedChairs.top().first <= cnt) {
                int chair = OccupiedChairs.top().second;
                unOccupiedChairs.push(chair);
                OccupiedChairs.pop();
            }

            int topChair = unOccupiedChairs.top();
            unOccupiedChairs.pop();

            if(arrival == targetFriendArrival)
                return topChair;

            // push arrival with leaving time
            OccupiedChairs.push({i[1], topChair});
        }

        return -1;
    }
};